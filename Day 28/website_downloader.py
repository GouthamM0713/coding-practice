from urllib.request import Request, urlopen
from urllib.error import URLError, HTTPError
from pathlib import Path


url = input("Enter website URL: ").strip()

if not url.startswith(("http://", "https://")):
    print("Please enter a valid HTTP or HTTPS URL.")

else:
    request = Request(
        url,
        headers={"User-Agent": "Python Website Downloader"}
    )

    try:
        with urlopen(request, timeout=15) as response:
            content = response.read()
            filename = Path("downloaded_page.html")

            filename.write_bytes(content)

            print("Website downloaded successfully!")
            print("HTTP status:", response.status)
            print("Saved as:", filename.resolve())

    except (HTTPError, URLError, TimeoutError, OSError) as error:
        print("Download failed:", error)