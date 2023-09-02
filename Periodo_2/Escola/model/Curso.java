package model;

public class Curso {
	private String sigla;
	private String nome;
	private int duracao;
	private Departamento departamento;
	
	public Curso() {}
	public Curso(String sigla, String nome, int duracao) {
		this.sigla = sigla;
		this.nome = nome;
		this.duracao = duracao;
	}
	public Curso(String sigla, String nome, int duracao, Departamento departamento) {
		this.sigla = sigla;
		this.nome = nome;
		this.duracao = duracao;
		this.departamento = departamento;
	}
	
	public String getSigla() {
		return sigla;
	}
	public void setSigla(String sigla) {
		this.sigla = sigla;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public int getDuracao() {
		return duracao;
	}
	public void setDuracao(int duracao) {
		this.duracao = duracao;
	}
	public Departamento getDepartamento() {
		return departamento;
	}
	public void setDepartamento(Departamento departamento) {
		this.departamento = departamento;
	}
	

}