let primerNumero = parseInt(prompt("Ingrese el primer número:"))
alert("El primer número ingresado es: " + primerNumero)

let segundoNumero = parseInt(prompt("Ingrese el segundo número:"))
alert("El segundo número ingresado es: " + segundoNumero)

var parImpar = (primerNumero + segundoNumero) % 2 === 0 ? "par" : "impar"

switch (parImpar) {
    case "par":
        alert("La potencia del primer número es: " + Math.pow(primerNumero, 2))
        alert("La potencia del segundo número es: " + Math.pow(segundoNumero, 2))
        break;
    case "impar":
        alert("La potencia del segundo número es: " + Math.pow(segundoNumero, 2))
        alert("La potencia del primer número es: " + Math.pow(primerNumero, 2)) 
        break;
    default:
        alert("No se pudo determinar si la suma es par o impar")
}



