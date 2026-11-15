from urllib.request import Request, urlopen
from html.parser import HTMLParser
from urllib.parse import urlparse

class MetadataParser(HTMLParser):
    def __init__(self):
        super().__init__()
        self.title = ""
        self.description = ""
        self.inside_title = False

    def handle_starttag(self, tag, attrs):
        attributes = dict(attrs)

        if tag == "title":
            self.inside_title = True

        if tag == "meta":
            if attributes.get("name", "").lower() == "description":
                self.description = attributes.get("content", "")

    def handle_endtag(self, tag):
        if tag == "title":
            self.inside_title = False

    def handle_data(self, data):
        if self.inside_title:
            self.title += data


url = input("Enter webpage URL: ").strip()

if urlparse(url).scheme not in ("http", "https") or not urlparse(url).netloc:
    print("Enter a valid HTTP or HTTPS URL.")
else:
    try:
        request = Request(
            url,
            headers={"User-Agent": "PythonMetadataExtractor/1.0"}
        )

        with urlopen(request, timeout=10) as response:
            content_type = response.headers.get_content_type()

            if content_type != "text/html":
                raise ValueError("The URL did not return an HTML page.")

            html = response.read(2_000_000).decode(
                response.headers.get_content_charset() or "utf-8",
                errors="replace"
            )

        parser = MetadataParser()
        parser.feed(html)

        print("\n--- Webpage Information ---")
        print("URL:", url)
        print("Title:", parser.title.strip() or "Not found")
        print("Description:", parser.description or "Not found")

    except Exception as error:
        print("Could not extract metadata:", error)