import datetime

start = datetime.datetime(year=1901, month=1, day=1)

ans = 0

while(start.year < 2001):
    ans += 1 if start.weekday() == 6 and start.day == 1 else 0
    start += datetime.timedelta(days=1)

print(ans)
