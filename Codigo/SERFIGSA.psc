SubProceso agregarCliente()
	Definir nombre, cedula, numSeguro, departamento, fechaNacimiento, fechaRegistro, email, telefono como Cadena;
	Escribir "========== Agregar Cliente ==========";
	Escribir "Ingrese el nombre completo del cliente";
	Leer nombre;
	Escribir "Ingrese el n�mero de c�dula";
	Leer cedula;
	Escribir "Ingrese el n�mero de seguro";
	Leer numSeguro;
	Escribir "Ingrese el departamento";
	Leer departamento;
	Escribir "Ingrese la fecha de nacimiento (DD/MM/AAAA)";
	Leer fechaNacimiento;
	Escribir "Ingrese la fecha de registro (DD/MM/AAAA)";
	Leer fechaRegistro;
	Escribir "Ingrese el correo electr�nico";
	Leer email;
	Escribir "Ingrese el n�mero de tel�fono";
	Leer telefono;
	Escribir "Cliente agregado exitosamente";
FinSubProceso

SubProceso editarCliente()
	Definir cedula, campo, nuevoValor como Cadena;
	Definir encontrado como Logico;
	encontrado <- Falso;
	Escribir "========== Editar Cliente ==========";
	Escribir "Ingrese el n�mero de c�dula del cliente que desea editar";
	Leer cedula;
	Para i <- 1 Hasta (clientes) Con Paso 1 Hacer
		Si clientes[i][5] <- cedula Entonces;
			encontrado <- Verdadero;
			Escribir "Ingrese el campo que desea editar:";
			Escribir "1. Nombre";
			Escribir "2. Tipo de Moneda";
			Escribir "3. Monto";
			Escribir "4. Inter�s";
			Escribir "5. N�mero de C�dula";
			Escribir "6. N�mero de N�mina";
			Escribir "7. N�mero de Seguro";
			Escribir "8. Departamento";
			Escribir "9. Centro de Costo";
			Escribir "10. Fecha de Nacimiento";
			Escribir "11. Fecha de Registro";
			Escribir "12. Correo Electr�nico";
			Escribir "13. N�mero de Tel�fono";
			Leer campo;
		FinSi
	FinPara
	Si campo <= 13 Entonces;
		Escribir "Ingrese el nuevo valor:";
		Leer nuevoValor;
		clientes [i][campo] <- nuevoValor;
		Escribir "Campo actualizado exitosamente";
	FinSi
	
	Si encontrado = Falso Entonces
		Escribir "Cliente no encontrado";
	FinSi
	
FinSubProceso

SubProceso eliminarCliente()
	Definir cedula como Cadena;
	Definir encontrado, i como Logico;
	encontrado <- Falso;
	Escribir "========== Eliminar Cliente ==========";
	Escribir "Ingrese el n�mero de c�dula del cliente que desea eliminar:";
	Leer cedula;
	Para i <- 1 Hasta (clientes) Con Paso 1 Hacer
		Si clientes[i][5] = cedula Entonces;
			encontrado <- Verdadero;
			Escribir "Cliente eliminado exitosamente";
		FinSi
		Si encontrado = Falso Entonces
			Escribir "Cliente no encontrado";
		FinSi
	FinPara
FinSubProceso


SubProceso buscarCliente()
	Definir cedula como Cadena;
	Definir encontrado como Logico;
	encontrado <- Falso;
	Escribir "========== Buscar Cliente ==========";
	Escribir "Ingrese el n�mero de c�dula del cliente que desea buscar:";
	Leer cedula;
	Para i <- 1 Hasta (clientes) Con Paso 1 Hacer
		Si clientes [i][5] <- cedula Entonces;
			encontrado <- Verdadero;
			Escribir "Nombre completo: ", clientes[i][1];
			Escribir "Tipo de Moneda: ", clientes[i][2];
			Escribir "Monto: ", clientes[i][3];
			Escribir "Inter�s: ", clientes[i][4];
			Escribir "N�mero de C�dula: ", clientes[i][5];
			Escribir "N�mero de N�mina: ", clientes[i][6];
			Escribir "N�mero de Seguro: ", clientes[i][7];
			Escribir "Departamento: ", clientes[i][8];
			Escribir "Centro de Costo: ", clientes[i][9];
			Escribir "Fecha de Nacimiento: ", clientes[i][10];
			Escribir "Fecha de Registro: ", clientes[i][11];
			Escribir "Correo Electr�nico: ", clientes[i][12];
			Escribir "N�mero de Tel�fono: ", clientes[i][13];
		FinSi
	FinPara
	Si encontrado = Falso Entonces
		Escribir "Cliente no encontrado";
	FinSi
FinSubProceso


SubProceso mostrarClientes()
	Escribir "========== Mostrar Todos los Clientes ==========";
	Si (clientes) > 0 Entonces
		Para i <- 1 Hasta (clientes) Con Paso 1 Hacer
			Escribir "Cliente ", i;
			Escribir "Nombre completo: ", clientes[i][1];
			Escribir "Tipo de Moneda: ", clientes[i][2];
			Escribir "Monto: ", clientes[i][3];
			Escribir "Inter�s: ", clientes[i][4];
			Escribir "N�mero de C�dula: ", clientes[i][5];
			Escribir "N�mero de N�mina: ", clientes[i][6];
			Escribir "N�mero de Seguro: ", clientes[i][7];
			Escribir "Departamento: ", clientes[i][8];
			Escribir "Centro de Costo: ", clientes[i][9];
			Escribir "Fecha de Nacimiento: ", clientes[i][10];
			Escribir "Fecha de Registro: ", clientes[i][11];
			Escribir "Correo Electr�nico: ", clientes[i][12];
			Escribir "N�mero de Tel�fono: ", clientes[i][13];
		FinPara
	Sino
		Escribir "No hay clientes registrados";
	FinSi
FinSubProceso




Proceso CronogramaPagoMicrofinanciera
    Definir clientes como caracter;
    Definir opc, i como Entero;
    opc <- 0;
    Mientras opc <> 6 Hacer
        Escribir "========== Menu Principal ==========";
        Escribir "1. Agregar Cliente";
        Escribir "2. Editar Cliente";
        Escribir "3. Eliminar Cliente;";
        Escribir "4. Buscar Cliente";
        Escribir "5. Mostrar Clientes";
        Escribir "6. Salir";
        Escribir "===================================";
	FinMientras
	
	Leer opc;
	Segun opc Hacer
		
		1:
			agregarCliente();
		2:
			editarCliente();
		3:
			eliminarCliente();
		4:
			buscarCliente();
		5:
			mostrarClientes();
		6:
			Escribir "�Hasta luego!";
		De Otro Modo:
			Escribir "Opci�n inv�lida, intente nuevamente";
			
	FinSegun
FinProceso