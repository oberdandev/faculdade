package tela;
import java.util.Scanner;

import controller.AlunoController;
import controller.CursoController;
import controller.DepartamentoController;

public class EscolaMenuInterface {
	public void mostrarMenu()
	{
		Scanner opcaoMenu = new Scanner(System.in);
		int opcao = 0;
		AlunoController alunoController = new AlunoController();
		CursoController cursoController = new CursoController();
		DepartamentoController departamentoController = new DepartamentoController();
		

		do
		{
			System.out.println("1 - Cadastrar um Aluno");
			System.out.println("2 - Listar Alunos");
			System.out.println("3 - Inserir um Curso");
			System.out.println("4 - Listar Cursos");
			System.out.println("5 - Cadastrar Departamento (Em construção, não utilizar)");
			System.out.println("6 - Listar Departamento (Em cosntrução, não utilizar)");
			System.out.println("7 - Cadastrar Departamento (Em construção, não utilizar)");
			System.out.println("7 - Listar Departamentos");
			System.out.println("9 - Sair");
			System.out.print("Escolha uma opção: ");
			opcao = opcaoMenu.nextInt();
			switch (opcao)
			{
			case 1:
				alunoController.cadastrar();
				break;
			case 2:
				alunoController.visualizar();
				break;
			case 3:
				cursoController.cadastrar();
				break;
			case 4:
				cursoController.visualizar();
				break;
			case 5:
				departamentoController.visualizar();
				break;
			case 9:
				System.out.println("Você escolheu sair!");
				break;
			default:
				System.out.println("Opção inexistente!");
				break;
			}
			
		} while (opcao != 9);
		
		opcaoMenu.close();
		System.out.print("\033[H\033[2J");
		System.exit(0);
	}
}
