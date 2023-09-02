package controller;

import java.util.ArrayList;
import java.util.List;

import model.Departamento;
import tela.DepartamentoInterface;

public class DepartamentoController {
	private List<Departamento> departamento = new ArrayList<Departamento>();
	
	public void cadastrar() {
		DepartamentoInterface departamento = new DepartamentoInterface();
		Departamento novoDepartamento = departamento.cadastrar();
		departamento.add(novoDepartamento);
	
	}
	
	public void visualizar() {}
	
	
}
