# CALCULADORA VERSION 1.0
# 4 OPERACIONES
#   + Suma 
#   - Resta 
#   x Multiplicacion 
#   / Division 

service Calculadora{
    void ping(),
    double suma(1:double num1, 2:double num2),
    double resta(1:double num1, 2:double num2),
    double multiplica(1:double num1, 2:double num2),
    double divide(1:double num1, 2:double num2),
}