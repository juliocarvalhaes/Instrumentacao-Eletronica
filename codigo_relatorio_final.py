import matplotlib.pyplot as plt
import pandas as pd
import math
# Nome do arquivo da planilha
planilha = 'dados_resumidos.xlsx'

# Lê a planilha como um dataframe
df = pd.read_excel(planilha)

# Loop através de cada coluna no dataframe
for coluna in df.columns:
    # Calcula a média da coluna
    media = df[coluna].mean()
    
    print("A média dos valores na coluna {} é {:.2f}".format(coluna, media))
    
#Calculando o angulo em relação a theta z, theta x e theta y:

#Exemplo "ideal" para o cálculo de theta z,y e x:
a_x = 0.00001 
a_y = 0.00001
a_z = 1

theta_z = math.atan(a_z/(math.sqrt(a_y*a_y + a_x*a_x)))
print(f"Valor do ângulo theta z (caso quase que ideal), em graus: {math.degrees(theta_z)}")

#Para theta y:

theta_y = math.atan(a_y/(math.sqrt(a_z*a_z + a_x*a_x)))
print(f"Valor do ângulo theta y (caso quase que ideal), em graus: {math.degrees(theta_y)}")

#Para Theta x:

theta_x = math.atan(a_x/(math.sqrt(a_y*a_y + a_z*a_z)))
print(f"Valor do ângulo theta x (caso quase que ideal), em graus: {math.degrees(theta_x)}")

#Exemplo para o caso concreto para o cálculo de theta z,y e x:

a_x = 0.018
a_y = 0.01
a_z = 0.94

theta_z = math.atan(a_z/(math.sqrt(a_y*a_y + a_x*a_x)))
print(f"Valor do ângulo theta z, em graus: {math.degrees(theta_z)}")

#Para theta y:

theta_y = math.atan(a_y/(math.sqrt(a_z*a_z + a_x*a_x)))
print(f"Valor do ângulo theta y, em graus: {math.degrees(theta_y)}")

#Para Theta x:

theta_x = math.atan(a_x/(math.sqrt(a_y*a_y + a_z*a_z)))
print(f"Valor do ângulo theta x, em graus: {math.degrees(theta_x)}")


#Angulo de 0°
erro1 = [0.04, 0.15, 0.13, 0.06, 0.03]
#Angulo de 45°
erro2 = [0.77, 0.76, 0.85, 0.85, 0.04]
#Angulo de 86°
erro3 = [0, 0.16, 0.5, 0.11 , 0.29]

# Criar o gráfico
plt.plot(erro1, label='Erro do ângulo de 0°')
plt.plot(erro2, label='Erro do ângulo de 45°')
plt.plot(erro3, label='Erro do ângulo de 86°')

plt.xlabel('Posição do Valor de Erro')
plt.ylabel('Valor do Erro de medição')
plt.title('Gráfico de erro de medição de ângulos')
plt.legend()



plt.show()


