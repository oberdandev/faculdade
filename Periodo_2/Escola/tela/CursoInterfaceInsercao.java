package tela;

import java.util.Scanner;

import model.Curso;

public class CursoInterfaceInsercao {
	public Curso inserirCurso()
	{
		Scanner scan = new Scanner(System.in);
		Scanner nomeCurso = new Scanner(System.in);
		
		System.out.printf("Insira a sigla do curso: ");
		String sigla = scan.next();
		
		System.out.printf("Insira o nome do curso: ");
		String nome = nomeCurso.nextLine();
		
		System.out.printf("Insira a duração em horas do curso: ");
		int duracao = scan.nextInt();
		
		Curso novo_curso = new Curso(sigla, nome, duracao);
		
		return novo_curso;
	}
}
