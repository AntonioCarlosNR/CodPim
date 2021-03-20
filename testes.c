#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30], cpf[10],nome_med[30],cpf_med[10],cpf_func[10],nome_func[30],expc[1],func[20], user[30];
    float nota;
    int codigo,dia[2],mes[2],unidade[3],funcuni1,funcuni2,funcuni3,UniPac[2];
}paciente;

int login (int *log)
{
    char login[15] = "MEU_LOGIN", cpf_func[10], nome_func[30];//Tem que ter mais espaço que a string. Pelo menos 1 a mais que a palavra.
    char login1[15]; //Pode ser do mesmo tamanho que o login
    char senha[15] = "MINHA_SENHA";
    char senha1[15];

    printf("LOGIN: ");
    scanf("%s",login1); //String se lê com %s
    if (strcmp(login, login1) == 0 || strcmp(nome_func, login1) == 0) //strcmp() é uma função da biblioteca string.h que compara 2 strings. Se for igual a 0 é porque as duas são iguais.
    {
    	printf("Usuario valido\n");
        printf("Senha: ");
        scanf("%s",senha1); //String se lê com %s
        if (strcmp(senha, senha1) == 0 || strcmp(cpf_func, senha1) == 0) //strcmp() é uma função da biblioteca string.h que compara 2 strings. Se for igual a 0 é porque as duas são iguais.
        {
    	printf("Logado\n");
        *log = 1;  
        }
        else
        {
            printf("Senha invalida!!\n");
        }
    }
    else
    {
    	printf("Usuario invalido!!\n");
    }   
    return log;
}

void exibeMenu(){
    printf("*** Menu ***\n");
		printf("[1] Agendamentos \n");
		printf("[2] Cadastro \n");
		printf("[3] Consultas \n");
		printf("[4] Relatório/Financeiro \n");
		printf("[0] Sair \n");
}

void exibeRelatorio(){
printf("Relatorios\n");
		printf("[1] Pacientes por unidade \n");
		printf("[2] Médicos por unidade \n");
		printf("[3] Funcionários por unidade\n");
		printf("[4] Unidade da rede que mais atende\n");
		printf("[5] Valor total adquirido diariamente\n");
		printf("[0] Voltar ao menu\n");
}

int main(){

    int i, cont= 0, result=0, opcao, codigo, tam=0,achou=0,cadastro_feito=0,unidade[3],pos,neg,tama,unidademed1=0,unidademed2=0,unidademed3=0,medUni,funcuni1=0,funcuni2=0,funcuni3=0,UniFunc,UniPac,achou2=0,unipac1=0,unipac2=0,unipac3=0,total,total2,total3,maiorPac,maiorFunc,maiorMed,valor1=0,valor2=0,valor3=0;
    paciente cadastro[tam];
    char nome[30], cpf[10], nome_med[30],cpf_med[10],cpf_func[10],nome_func[30],expc[1],func[20];

    login(&result);
    printf("%s",nome_func);

    if(result != 1)
    {
        do{
            login(result);
            cont ++;
        }while(cont <= 3);
        
    }
    else
    {
       printf("Seguiu");
    }

return 0;
}