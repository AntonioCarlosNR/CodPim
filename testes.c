#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct{
    char nome[300], cpf[10],nome_med[30],cpf_med[10],cpf_func[10],nome_func[30],expc[1],func[20], user[30];
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
		printf("[1] Cadastrar paciente \n");
		printf("[2] Cadastrar agendamento do paciente \n");
		printf("[3] Cadastrar médicos \n");
		printf("[4] Cadastrar funcionários \n");
		printf("[5] Feedback dos pacientes \n");
		printf("[6] Relatório das Unidades \n");
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

    int cont= 0, result=0, opcao, codigo, tam=0,achou=0,cadastro_feito=0,unidade[3],pos,neg,tama,unidademed1=0,unidademed2=0,unidademed3=0,medUni=0,funcuni1=0,funcuni2=0,funcuni3=0,UniFunc,UniPac,achou2=0,unipac1=0,unipac2=0,unipac3=0,total,total2,total3,maiorPac,maiorFunc,maiorMed,valor1=0,valor2=0,valor3=0;
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
        do{
        exibeMenu();
        printf("Escolha a opção: ");
		scanf("%d", &opcao);

		switch (opcao){

            case 1:
                fflush(stdin);
                printf("20 reais o cadastro!\n");
                fflush(stdin);

                //gerando arquivo em txt
                FILE *pont_arq;

                //abrindo o arquivo 
                pont_arq=fopen("Cadastro de pacientes.txt","a");

                //testando se o arquivo foi realmente criado
                if(pont_arq == NULL)
                {
                printf("Erro na abertura do arquivo!");
                return 1;
                } 
                else
                {
                    printf("Cadastro de pacientes: \n");
                    
                        printf("\nInforme o CPF do paciente: ");
                        setbuf(stdin,0);
                        fgets(cpf,10,stdin);
                        printf("%s",cpf);

                        system("pause");

                        printf("\nInforme o nome do paciente: ");
                        setbuf(stdin,0);
                        fgets(nome,30,stdin);
                        printf("%s",nome);

                        system("pause");

                        printf("Informe a unidade do paciente 1,2 ou 3: \n");
                        scanf("%d",&UniPac);

                        switch (UniPac){
                            case 1: unipac1=unipac1 + 1;
                                valor1=valor1+1;
                                system("pause");
                                system("cls");
                                break;
                            case 2: unipac2=unipac2 +1;
                                valor2=valor2+1;
                                system("pause");
                                system("cls");
                                break;
                            case 3: unipac3=unipac3 +1;
                                valor3=valor3+1;

                                system("pause");
                                system("cls");
                                break;
                            default: printf("\nEssa opção não existe. Escolha uma opção válida! \n");    
                        }
                        //usando fprintf para armazenar a string no arquivo
                        fprintf(pont_arq, "%s", nome);
                        fprintf(pont_arq, "%s", cpf);
                        fprintf(pont_arq, "/==========/");

                        //fechando arquivo
                        fclose(pont_arq);
                        printf("Dados gravados com sucesso!");
                    
                }
            cadastro_feito++;
            printf("\nCadastro realizado com sucesso! \n");
            system("pause");
            system("cls");
            break;

                

            case 2: fflush(stdin);
               
            system("pause");
            system("cls");
            break;
    
                
            

            case 3: 
                fflush(stdin);
                printf("Cadastro de médicos: \n");

                //gerando arquivo em txt
                FILE *pont_arqM;

                //abrindo o arquivo 
                pont_arqM = fopen("Cadastro de medicos.txt","a");

                //testando se o arquivo foi realmente criado
                if(pont_arqM == NULL)
                {
                printf("Erro na abertura do arquivo!");
                return 1;
                }
                else
                {
                    printf("\nInforme o CPF do médico: ");
                    setbuf(stdin,0);
                    fgets(cpf_med, 10,stdin);
                    system("pause");

                    printf("Informe o nome do médico: ");
                    setbuf(stdin,0);
                    fgets(nome_med, 30,stdin);
                    system("pause");

                    printf("\nInforme a especialidade do médico: ");
                    setbuf(stdin,0);
                    fgets(func, 20,stdin);
                    system("pause");

                    printf("\nInforme a unidade do médico 1,2 ou 3: ");
                    scanf("%d",&medUni);

                    switch (medUni){
                        case 1: 
                            unidademed1 = unidademed1 + 1;
                        break;
                        case 2: 
                            unidademed2 = unidademed2 +1;
                        break;
                        case 3: 
                            unidademed3 = unidademed3 +1;
                        break;

                        default: 
                            printf("\nEssa opção não existe. Escolha uma opção válida! \n");
                    }
                        //usando fprintf para armazenar a string no arquivo
                        fprintf(pont_arqM, "\n");
                        fprintf(pont_arqM, "%s", nome_med);
                        fprintf(pont_arqM, "%s", cpf_med);
                        fprintf(pont_arqM, "%s", func);
                        fprintf(pont_arqM, "/==========/");

                        //fechando arquivo
                        fclose(pont_arqM);
                        printf("Dados gravados com sucesso!");
                }

            printf("Cadastro realizado com sucesso!\n");
            system("pause");
            system("cls");
            break;

            case 4: 
                    fflush(stdin);
    
            system("pause");
            system("cls");
            break;

            case 5:
            system("pause");
            system("cls");
            break;

            case 6:
                system("pause");
            system("cls");
            break;
        }
    }while (opcao != 0);
    }

return 0;
}