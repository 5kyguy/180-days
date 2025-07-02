import json
from datetime import datetime, timedelta
import os

# Load the JSON data
with open('typing-data.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

# Update the timeStamp for each item in the data
# to match the date range from 2025-07-01 to today
start_date = datetime(2025, 7, 1).date()
end_date = datetime.now().date()

no_of_days = (end_date - start_date).days + 1

for day in range(no_of_days):
    current_date = start_date + timedelta(days=day)
    current_date_str = current_date.isoformat()

    for item in data:
        if item['timeStamp'][:10] == current_date_str:
            item['timeStamp'] = current_date_str

            # Filter items for the current date
            items_for_day = [item for item in data if item['timeStamp'] == current_date_str]

            # Save to stats.json in the next day's folder
            with open(f"typing/{current_date_str}/stats.json", "w", encoding="utf-8") as out_f:
                json.dump(items_for_day, out_f, ensure_ascii=False, indent=2)