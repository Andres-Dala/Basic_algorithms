import math

#Función para determinar si un numero n es primo
def primo(n):
    if n<=1:
        return False
    if n==2:
        return True
    for i in range(2,math.ceil(math.sqrt(n))+1):
        if n%i==0:
            return False
    return True

#Funcion para determinar el n-esimo termino de la sucesion Fibonacci
def fib(n):
    if n==1 or n==2:
        return 1
    else:
        return fib(n-1)+fib(n-2)