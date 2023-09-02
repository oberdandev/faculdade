package model;

public class Departamento {
	private String nome;
	private String sigla;
	private Campus campus;
	
	public Departamento() {}
	
	public Departamento(String nome, String sigla) {
		this.nome = nome;
		this.sigla = sigla;
	}
	
	public Departamento(String nome, String sigla, Campus campus) {
		this.nome = nome;
		this.sigla = sigla;
		this.campus = campus;
	}
	
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getSigla() {
		return sigla;
	}
	public void setSigla(String sigla) {
		this.sigla = sigla;
	}
	public Campus getCampus() {
		return campus;
	}
	public void setCampus(Campus campus) {
		this.campus = campus;
	}
	
	
}
