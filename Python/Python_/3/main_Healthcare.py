import pandas as pd
from sodapy import Socrata

# Unauthenticated client only works with public data sets. Note 'None'
# in place of application token, and no username or password:
client = Socrata("data.medicare.gov", None)

# Example authenticated client (needed for non-public datasets):
# client = Socrata(data.medicare.gov,
#                  MyAppToken,
#                  userame="user@example.com",
#                  password="AFakePassword")

# First 2000 results, returned as JSON from API / converted to Python list of
# dictionaries by sodapy.
results_list = client.get("sw5q-qq7y.csv?percent_of_patients_who_reported_yes_they_would_definitely_recommend_the_home_health_agency_to_fri_1=1", limit=2000)

print(results_list)
# Convert to pandas DataFrame
results_df = pd.DataFrame.from_records(results_list)
#print(results_df)
