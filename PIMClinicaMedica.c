#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30], cpf[10],nome_med[30],cpf_med[10],cpf_func[10],nome_func[30],expc[1],func[20], user[30];
    float nota;
    int codigo,dia[2],mes[2],unidade[3],funcuni1,funcuni2,funcuni3,UniPac[2];
}paciente;


int login (int *log)
{
    char login[15] = "MEU_LOGIN", cpf_func[10], nome_func[30], login1[15], senha[15] = "MINHA_SENHA", senha1[15];

    printf("\nLOGIN: ");
    scanf("%s",login1);
    if (strcmp(login, login1) == 0 || strcmp(nome_func, login1) == 0) //strcmp() é uma função da biblioteca string.h que compara 2 strings. Se for igual a 0 é porque as duas são iguais.
    {
    	printf("Usuario valido\n");
        printf("Senha: ");
        scanf("%s",senha1);
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
		printf("[2] Agendamento de Consultas \n");
		printf("[3] Cadastrar medicos \n");
		printf("[4] Cadastrar funcionarios \n");
		printf("[5] Feedback dos clientes \n");
		printf("[6] Relatorio\n");
		printf("[0] Logout \n");
}

void exibeRelatorio(){
printf("\nRelatorios\n");
		printf("[1] Pacientes por unidade \n");
		printf("[2] Medicos por unidade \n");
		printf("[3] Funcionarios por unidade\n");
		printf("[4] Unidade da rede que mais atende\n");
		printf("[5] Financeiro diario\n");
		printf("[0] Logout\n");
}

void main(){

    int i, cont= 0, result=0, expc = 0, opcao, codigo, tam=0,achou=0,cadastro_feito=0,unidade[3],pos,neg,tama,unidademed1=0,unidademed2=0,unidademed3=0,medUni,funcuni1=0,funcuni2=0,funcuni3=0,UniFunc,UniPac,achou2=0,unipac1=0,unipac2=0,unipac3=0,total,total2,total3,maiorPac,maiorFunc,maiorMed,valor1=0,valor2=0,valor3=0;
    paciente cadastro[tam];
    char nome[30], cpf[10], nome_med[30],cpf_med[10],cpf_func[10],nome_func[30],func[20],dia[20],mes[20];

    printf("\nBem vindo ao aplicativo de Gestao de clinicas medicas!!!\n");
    login(&result);

    if(result != 1)
    {
        do{
            login(result);
            cont ++;
        }while(cont < 3);
        printf("O sistema sera encerrado\n\nTente novamente mais tarde.\n");
    }
    else
    {
            do{
            exibeMenu();
            printf("Escolha a opcao: ");
            scanf("%d", &opcao);

            switch (opcao){

                case 1:
                    fflush(stdin);
                    printf("100 reais o cadastro com agendamento!\n");
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

                            system("pause");

                            printf("\nInforme o nome do paciente: ");
                            setbuf(stdin,0);
                            fgets(nome,30,stdin);

                            system("pause");

                            printf("Informe a unidade do paciente 1,2 ou 3: \n");
                            scanf("%d",&UniPac);

                            switch (UniPac){
                                case 1: 
                                    unipac1=unipac1 + 1;
                                    valor1=valor1+1;
                                    system("pause");
                                    system("cls");
                                    break;

                                case 2: 
                                    unipac2=unipac2 +1;
                                    valor2=valor2+1;
                                    system("pause");
                                    system("cls");
                                    break;

                                case 3: 
                                    unipac3=unipac3 +1;
                                    valor3=valor3+1;
                                    system("pause");
                                    system("cls");
                                    break;

                                default: 
                                    printf("\nEssa opcao nao existe. Escolha uma opcao valida! \n");    
                            }
                            //usando fprintf para armazenar a string no arquivo
                            fprintf(pont_arq, "\n");
                            fprintf(pont_arq, "Nome do paciente: %s", nome);
                            fprintf(pont_arq, "CPF do paciente: %s", cpf);
                            fprintf(pont_arq, "Unidade: %d", UniPac);
                            fprintf(pont_arq, "\n/==========//==========/");
                            
                            //fechando arquivo
                            fclose(pont_arq);
                            printf("Dados gravados com sucesso!\n");
                        
                    }
                cadastro_feito++;
                printf("\nCadastro realizado com sucesso! \n");
                system("pause");
                system("cls");
                break;


                case 2: 
                    printf("Agendamento de Consultas!");

                    printf("\nInforme seu CPF: ");
                    setbuf(stdin,0);
                    fgets(cpf,10,stdin);

                    system("pause");
                    
                    //gerando arquivo em txt
                    FILE *pont_arqAg;

                    //abrindo o arquivo 
                    pont_arqAg=fopen("Agendamento de consulta.txt","a");

                    //testando se o arquivo foi realmente criado
                    if(pont_arqAg == NULL)
                    {
                    printf("Erro na abertura do arquivo!");
                    return 1;
                    } 
                    else
                    {
                    printf("Digite o dia do agendamento: \n");
                    setbuf(stdin,0);
                    fgets(dia,20,stdin);

                    system("pause");
                    
                    printf("Digite o mes do agendamento: \n");
                    setbuf(stdin,0);
                    fgets(mes,20,stdin);
                    
                    system("pause");

                    //usando fprintf para armazenar a string no arquivo
                    fprintf(pont_arqAg, "\n");
                    fprintf(pont_arqAg, "CPF do paciente: %s", cpf);
                    fprintf(pont_arqAg, "Dia: %s", dia);
                    fprintf(pont_arqAg, "Mes: %s", mes);
                    fprintf(pont_arqAg, "\n/==========//==========/");
                    
                    //fechando arquivo
                    fclose(pont_arqAg);
                    printf("Dados gravados com sucesso!\n");

                    }
                
                system("pause");
                system("cls");
                break;

                case 3: 
                    fflush(stdin);
                    printf("Cadastro de medicos: \n");

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
                        printf("\nInforme o CPF do medico: ");
                        setbuf(stdin,0);
                        fgets(cpf_med, 10,stdin);
                        system("pause");

                        printf("Informe o nome do medico: ");
                        setbuf(stdin,0);
                        fgets(nome_med, 30,stdin);
                        system("pause");

                        printf("\nInforme a especialidade do medico: ");
                        setbuf(stdin,0);
                        fgets(func, 20,stdin);
                        system("pause");

                        printf("\nInforme a unidade do medico 1,2 ou 3: ");
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
                                printf("\nEssa opcao nao existe. Escolha uma opcao valida! \n");
                        }
                            //usando fprintf para armazenar a string no arquivo
                            fprintf(pont_arqM, "\n");
                            fprintf(pont_arqM, "Nome do medico: %s", nome_med);
                            fprintf(pont_arqM, "CPF do medico: %s", cpf_med);
                            fprintf(pont_arqM, "Especialidade: %s", func);
                            fprintf(pont_arqM, "Unidade que atua: %d", medUni);
                            fprintf(pont_arqM, "\n/==========//==========/");

                            //fechando arquivo
                            fclose(pont_arqM);
                            printf("Dados gravados com sucesso!\n");
                    }

                printf("Cadastro realizado com sucesso!\n");
                system("pause");
                system("cls");
                break;


                case 4: 

                    printf("Cadastro de funcionarios: \n");
                    //gerando arquivo em txt
                    FILE *pont_arqF;

                    //abrindo o arquivo 
                    pont_arqF = fopen("Cadastro de funcionarios.txt","a");

                    //testando se o arquivo foi realmente criado
                    if(pont_arqF == NULL)
                    {
                    printf("Erro na abertura do arquivo!");
                    return 1;
                    }
                    else
                    {
                        printf("\nInforme o CPF do funcionario: ");
                        setbuf(stdin,0);
                        fgets(cpf_func, 10,stdin);
                        system("pause");

                        printf("Informe o nome do funcionario: ");
                        setbuf(stdin,0);
                        fgets(nome_func, 30,stdin);
                        system("pause");

                        printf("Informe a unidade do funcionario 1,2 ou 3: ");
                        scanf("%d",&UniFunc);
                        switch (UniFunc){
                            case 1: 
                                funcuni1=funcuni1 + 1;
                                system("pause");
                                system("cls");
                                break;
                            case 2: 
                                funcuni2=funcuni2 +1;
                                system("pause");
                                system("cls");
                                break;
                            case 3: 
                                funcuni3=funcuni3 +1;
                                system("pause");
                                system("cls");
                                break;

                            default: 
                            printf("\nEssa opcao nao existe. Escolha uma opcao valida! \n");
                        }
                        //usando fprintf para armazenar a string no arquivo
                        fprintf(pont_arqF, "\n");
                        fprintf(pont_arqF, "Nome do funcionario: %s", nome_func);
                        fprintf(pont_arqF, "CPF do Funcionario: %s", cpf_func);
                        fprintf(pont_arqF, "Unidade do funcionario: %d", UniFunc);
                        fprintf(pont_arqF, "\n/==========//==========/");

                        //fechando arquivo
                        fclose(pont_arqF);
                        printf("Dados gravados com sucesso!\n");
                    }
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

                        printf("\nInforme a unidade que o atendeu:");
                        setbuf(stdin,0);
                        fgets(unidade,3,stdin);
                        system("pause");

                        printf("\nVoce teve uma boa experiencia com a unidade?: \n");
                        printf("1-sim ou 2-nao: ");
                            scanf("%d",&expc);

                            if (expc == 1)
                            {
                                pos=pos+1;
                
                                //usando fprintf para armazenar a string no arquivo
                                fprintf(pont_arqFe, "\n");
                                fprintf(pont_arqFe, "Nome: %s", nome);
                                fprintf(pont_arqFe, "Unidade: %s", unidade);
                                fprintf(pont_arqFe, "Feedback positivo");
                                fprintf(pont_arqFe, "\n/==========//==========/");

                                printf("\nDados gravados com sucesso!\n");
                                printf("\nFeedback realizado com sucesso! \n");

                            }
                            else if(expc == 2) 
                            {
                                neg=neg+1;

                                fprintf(pont_arqFe, "\n");
                                fprintf(pont_arqFe, "%s", nome);
                                fprintf(pont_arqFe, "%s", unidade);
                                fprintf(pont_arqFe, "Feedback negativo");
                                fprintf(pont_arqFe, "\n/==========//==========/");

                                printf("Dados gravados com sucesso!\n");
                                printf("\nFeedback realizado com sucesso! \n");

                            }
                            else
                            {
                                printf("Por favor entre somente com s para sim ou n para nao\n");
                                printf("\nFeedback NAO realizado!\n");
                            }
                        //fechando arquivo
                        fclose(pont_arqFe);       
                    }

                system("pause");
                system("cls");
                break;

                case 6:
                    do{
                        exibeRelatorio();
                        printf("Escolha a opcao: ");
                        scanf("%d",&opcao);
                        
                        switch(opcao){

                            case 1:
                               
                                printf("\nPacientes registrados na unidade 1:%d\n",unipac1);                              
                                printf("\nPacientes registrados na unidade 2:%d\n",unipac2);                               
                                printf("\nPacientes registrados na unidade 3:%d\n",unipac3);                               
                                printf("\nPacientes em total das unidades:%d\n",unipac1+unipac2+unipac3);
                                printf("\nPara mais detalhes busque o arquivo 'Cadastro de pacientes.txt'\n");

                                system("pause");
                                system("cls");
                                break;

                            case 2:
                                printf("\nMedicos registrados na unidade 1:%d\n",unidademed1);
                                printf("\nMedicos registrados na unidade 2:%d\n",unidademed2);
                                printf("\nMedicos registrados na unidade 3:%d\n",unidademed3);
                                printf("\nTotal de medicos registrados nas unidades: %d",unidademed1+unidademed2+unidademed3);

                                printf("\nPara mais detalhes busque o arquivo 'Cadastro de medicos.txt'\n");

                                system("pause");
                                system("cls");
                                break;

                            case 3:
                                printf("\nFuncionarios registrados na unidade 1:%d\n",funcuni1);
                                printf("\nFuncionarios registrados na unidade 2:%d\n",funcuni2);
                                printf("\nFuncionarios registrados na unidade 3:%d\n",funcuni3);
                                printf("\nTotal de funcionarios registrados:%d\n",funcuni1+funcuni2+funcuni3);

                                printf("\nPara mais detalhes busque o arquivo 'Cadastro de funcionarios.txt'\n");

                                system("pause");
                                system("cls");
                                break;

                            case 4:
                                maiorPac=unipac1;
                                if  (unipac2>maiorPac)
                                    maiorPac=unipac2;

                                if (unipac3>maiorPac)
                                    maiorPac=unipac3;

                                if (maiorPac=unipac1)
                                {
                                printf("\nUnidade que mais atende pacientes eh a unidade 1\n");
                                }
                                else if (maiorPac=unipac2)
                                {
                                printf("\nUnidade que mais atende pacientes eh a unidade 2\n");
                                }
                                else if (maiorPac=unipac3)
                                {
                                printf("\nUnidade que mais atende pacientes eh a unidade 3\n");
                                }
                                    maiorFunc=funcuni1;
                                    if  (funcuni2>maiorFunc)
                                        maiorFunc=funcuni2;
                                    if (funcuni3>maiorFunc)
                                        maiorFunc=funcuni3;
                                if (maiorFunc=funcuni1)
                                {
                                printf("\nUnidade com o maior numero de funcionarios eh a unidade 1\n");
                                }
                                else if (maiorFunc=funcuni2)
                                {
                                printf("\nUnidade com o maior numero de funcionarios eh a unidade 2\n");
                                }
                                else if (maiorFunc=funcuni3)
                                {
                                printf("\nUnidade com o maior numero de funcionarios eh a unidade 3\n");
                                }
                                maiorMed=unidademed1;
                                if (unidademed2>maiorMed)
                                    maiorMed=unidademed2;

                                if (unidademed3>maiorMed)
                                maiorMed=unidademed3;

                                if (maiorMed=unidademed1)
                                {
                                printf("\nA unidade com o maior numero de medicos eh a unidade 1\n");
                                }
                                else if (maiorMed=unidademed2)
                                {
                                printf("\nA unidade com o maior numero de medicos eh a unidade 2\n");
                                }
                                else if (maiorMed=unidademed3)
                                {
                                printf("\nA unidade com o maior numero de medicos eh a unidade 3\n");
                                }

                                system("pause");
                                system("cls");
                                break;

                            case 5: 
                                printf("\nValor faturado pela unidade 1 no dia: %d\n",valor1*100);
                                printf("\nValor faturado pela unidade 2 no dia: %d\n",valor2*100);
                                printf("\nValor faturado pela unidade 3 no dia: %d\n",valor3*100);
                                printf("\nValor total de todas unidades no dia: %d\n",valor1*100,valor2*100,valor3*100);

                            case 0:
                                system("pause");
                                system("cls");
                                break;
                        }
                }while (opcao !=0);
                
                case 0: printf("\nPrograma finalizado! \n");
                        printf("\nTchau!!");
                        break;

                default: printf("\nEssa opcao nao existe. Escolha uma opcao valida! \n");
            }
        }while (opcao != 0);
    }
}

