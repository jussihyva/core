import pandas as pd
import plotly.express as px

df = pd.read_csv('bench/data.csv')

fig = px.line(df, x='xxx', y=['yyy','zzz'], title='test')
fig.show()
fig.write_image('img.png')
