from datetime import datetime

entry = datetime.strptime(
    input("Enter entry time (HH:MM): "),
    "%H:%M"
)

exit_time = datetime.strptime(
    input("Enter exit time (HH:MM): "),
    "%H:%M"
)

if exit_time < entry:
    from datetime import timedelta
    exit_time += timedelta(days=1)

duration = exit_time - entry
hours = duration.total_seconds() / 3600

charged_hours = int(hours) + (1 if hours % 1 else 0)

rate = 20
fee = charged_hours * rate

print("Parking duration:", round(hours, 2), "hours")
print("Charged hours:", charged_hours)
print("Total parking fee: Rs.", fee)