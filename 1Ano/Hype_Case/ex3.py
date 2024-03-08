# -*- coding: utf-8 -*-
"""ex3.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1PGvVfoyXdcyLzuxE41TtYB2sazNNAJ0m
"""

#Função que calcula o menor lucro de uma lista enviada pelo úsuario de lucros.
#A função define a variável minimo como o primeiro valor da lista.
#Para cada item da lista a função vai comparar:
  #Se o primeiro valor (minimo) é menor ou maior do que o valor comparado.
  #Se o (minimo) for maior do que o valor comparado, o (minimo) se torna o valor comparado da lista.
#Após encontrar o menor valor da lista, ele retorna este valor para o úsuario.
def menor_lucro(lista_lucros):
  minimo = lista_lucros[0]
  for valor_lucro in lista_lucros[0:]:
    if valor_lucro < minimo:
      minimo = valor_lucro
  return minimo