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
    char nome[30], cpf[10], nome_med[30],cpf_med[10],cpf_func[10],nome_func[30],func[20];
    int expc = 0;

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
                
            system("pause");
            system("cls");
            break;

                

            case 2: fflush(stdin);
               
            system("pause");
            system("cls");
            break;
    
                
            

            case 3: 
                
            system("pause");
            system("cls");
            break;

            case 4: 
               
            printf("Cadastro realizado com sucesso! \n");
            system("pause");
            system("cls");
            break;

            case 5:
                printf("***Feedback dos clientes*** \n");
                fflush(stdin);

                //gerando arquivo em txt
                FILE *pont_arqFe;

                //abrindo o arquivo 
                pont_arqFe = fopen("Feedback clientes.txt","a");

                //testando se o arquivo foi realmente criado
                if(pont_arqFe == NULL)
                {
                printf("Erro na abertura do arquivo!");
                return 1;
                }
                else
                {
                    printf("\nInforme o seu nome: ");
                    setbuf(stdin,0);
                    fgets(nome, 30,stdin);
                    system("pause");

                    printf("Informe a unidade que o atendeu:");
                    setbuf(stdin,0);
                    fgets(unidade,3,stdin);
                    system("pause");

                    printf("Voce teve uma boa experiencia com a unidade?: \n");
                    printf("1-sim ou 2-não: ");
                        scanf("%d",&expc);

                        if (expc == 1)
                        {
                            pos=pos+1;
            
                            //usando fprintf para armazenar a string no arquivo
                            fprintf(pont_arqFe, "\n");
                            fprintf(pont_arqFe, "%s", nome);
                            fprintf(pont_arqFe, "%s", unidade);
                            fprintf(pont_arqFe, "Feedback positivo");
                            fprintf(pont_arqFe, "\n/==========/");

                            printf("Dados gravados com sucesso!\n");
                            printf("\nFeedback realizado com sucesso! \n");

                        }
                        else if(expc == 2) 
                        {
                            neg=neg+1;

                            fprintf(pont_arqFe, "\n");
                            fprintf(pont_arqFe, "%s", nome);
                            fprintf(pont_arqFe, "%s", unidade);
                            fprintf(pont_arqFe, "Feedback negativo");
                            fprintf(pont_arqFe, "\n/==========/");

                            printf("Dados gravados com sucesso!\n");
                            printf("\nFeedback realizado com sucesso! \n");

                        }
                        else
                        {
                            printf("Por favor entre somente com s para sim ou n para não\n");
                            printf("\nFeedback NÃO realizado!\n");
                        }
                    //fechando arquivo
                    fclose(pont_arqFe);       
                }

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