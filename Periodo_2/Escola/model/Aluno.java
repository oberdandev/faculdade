package model;
public class Aluno {
	
	private String matricula;
	private String nome;
	private Curso curso;
	
	public Aluno() {}
	public Aluno(String matricula, String nome)
	{
		setNome(nome);
		setMatricula(matricula);
	}
	
	public Aluno(String matricula, String nome, Curso curso) {
		this.matricula = matricula;
		this.nome = nome;
		this.curso = curso;
	}
	
	public String getMatricula()
	{
		 return this.matricula;
	}	
	
	public Curso getCurso() {
		return this.curso;
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;	
	}
	
	public void setCurso(Curso curso){
		this.curso = curso;
	}
	
	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}
	
	
	
}