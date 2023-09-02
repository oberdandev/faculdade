package controller;

import java.util.ArrayList;
import java.util.List;

import model.Aluno;
import tela.AlunoInterfaceCadastro;

public class AlunoController {
	private List<Aluno> alunos = new ArrayList<Aluno>();
	
	public void cadastrar()
	{
		AlunoInterfaceCadastro aic = new AlunoInterfaceCadastro();
		alunos.add(aic.cadastrarAluno());
		System.out.printf("Total de Alunos: %d\n", alunos.size());
	}
	
	public void visualizar()
	{
		int i = 0;
		for (Aluno aluno:alunos)
		{
			System.out.printf("ALUNO %d\t Matrícula: %s\t Nome: %s\n", i, aluno.getMatricula(), aluno.getNome());
			i++;
		}
		System.out.printf("\n");
	}

}
