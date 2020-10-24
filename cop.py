from math import factorial
def prob(k,n,p): #probability of k events happening within n range with p chance
    return factorial(n) / (factorial(k) * factorial(n - k)) * p**k * (1 - p)**(n - k)
def probmax(k,n,p): #probability of maximum of k events happening within n range
    return sum([prob(i, n, p) for i in range(k + 1)])
def probmin(k,n,p): #probability of minimum of k events happening within n range
    return sum([prob(i, n, p) for i in range(k, n + 1)])
print (prob(14,14,0.75))
    
    