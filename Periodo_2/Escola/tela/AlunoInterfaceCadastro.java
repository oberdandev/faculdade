package tela;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.Scanner;

import model.Aluno;
import model.Curso;

public class AlunoInterfaceCadastro {
	public Aluno cadastrarAluno()
	{
		String matricula = "";
		Curso curso = null;
		Scanner scan = new Scanner(System.in);
		Scanner eNomeAluno = new Scanner(System.in);
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		System.out.print("Informe a matrícula do aluno: ");
		matricula = scan.next();
		
		System.out.print("Informe o nome do aluno: ");
		String nome = eNomeAluno.nextLine();
		
		Aluno novo_aluno = new Aluno (matricula, nome, curso);
		
		return novo_aluno;	
	}
	
	public void visualizarAluno(Aluno aluno)
	{
		
	}
}
