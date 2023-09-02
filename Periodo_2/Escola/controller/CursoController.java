package controller;

import java.util.ArrayList;
import java.util.List;

import model.Curso;
import tela.CursoInterfaceInsercao;

public class CursoController {
	List<Curso> cursos = new ArrayList<Curso>();
	
	public void cadastrar()
	{
		CursoInterfaceInsercao cii = new CursoInterfaceInsercao();
		cursos.add(cii.inserirCurso());
		System.out.printf("Total de Cursos: %d\n", cursos.size());
	}
	
	public void visualizar()
	{
		int i = 0;
		for (Curso curso:cursos)
		{
			System.out.printf("CURSO %d\t Sigla: %s\t Nome: %s\t\t Duração: %dh\n", i, curso.getSigla(), curso.getNome(), curso.getDuracao());
			i++;
		}
		System.out.printf("\n");
	}

}
