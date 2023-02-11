import pandas as pd
# Nome do arquivo da planilha
planilha = 'dados_resumidos.xlsx'

# Lê a planilha como um dataframe
df = pd.read_excel(planilha)

# Loop através de cada coluna no dataframe
for coluna in df.columns:
    # Calcula a média da coluna
    media = df[coluna].mean()
    
    print("A média dos valores na coluna {} é {:.2f}".format(coluna, media))

