#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct{
    char nome[30], cpf[10],nome_med[30],cpf_med[10],cpf_func[10],nome_func[30],expc[1],func[20], user[30];
    float nota;
    int codigo,dia[2],mes[2],unidade[3],funcuni1,funcuni2,funcuni3,UniPac[2];
}paciente;


int login (int *log)
{
    char login[15] = "MEU_LOGIN", cpf_func[10], nome_func[30], login1[15], senha[15] = "MINHA_SENHA", senha1[15];

    printf("LOGIN: ");
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

void main(){
    setlocale(LC_ALL, "");

    int i, cont= 0, result=0, opcao, codigo, tam=0,achou=0,cadastro_feito=0,unidade[3],pos,neg,tama,unidademed1=0,unidademed2=0,unidademed3=0,medUni,funcuni1=0,funcuni2=0,funcuni3=0,UniFunc,UniPac,achou2=0,unipac1=0,unipac2=0,unipac3=0,total,total2,total3,maiorPac,maiorFunc,maiorMed,valor1=0,valor2=0,valor3=0;
    paciente cadastro[tam];
    char nome[30], cpf[10], nome_med[30],cpf_med[10],cpf_func[10],nome_func[30],expc[1],func[20];

    printf("Bem vindo ao aplicativo de Gestão de clinicas médicas!!!\n");
    login(&result);

    if(result != 1)
    {
        do{
            login(result);
            cont ++;
        }while(cont <= 3);
        printf("O sistema será encerrado\n Tente novamente mais tarde.\n");
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
                                    printf("\nEssa opção não existe. Escolha uma opção válida! \n");    
                            }
                            //usando fprintf para armazenar a string no arquivo
                            fprintf(pont_arq, "\n");
                            fprintf(pont_arq, "%s", nome);
                            fprintf(pont_arq, "%s", cpf);
                            fprintf(pont_arq, "%d", UniPac);
                            fprintf(pont_arq, "\n/==========/");
                            
                            //fechando arquivo
                            fclose(pont_arq);
                            printf("Dados gravados com sucesso!\n");
                        
                    }
                cadastro_feito++;
                printf("\nCadastro realizado com sucesso! \n");
                system("pause");
                system("cls");
                break;


                case 2: fflush(stdin);
                    if (cadastro_feito==0){
                    printf("Os pacientes não foram cadastrados!\n");
                }else{
                    fflush(stdin);
                        printf("\nInforme seu CPF: ");
                        gets(cpf);
                        achou = 0;

                        for (i = 0; i < tama; i++){
                            if (strcmp(cpf, cadastro[i].cpf) == 0){
                                achou = 1;
                                printf("Digite o dia do agendamento: \n");
                                    gets(cadastro[i].dia);
                                    fflush(stdin);
                                printf("Digite o mes do agendamento: \n");
                                    gets(cadastro[i].mes);
                                    fflush(stdin);
                            }
                        }
                            fflush(stdin);
                        if (achou == 0)
                            printf("O CPF digitado não foi encontrado! Digite um CPF válido! \n");
                }
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
                            fprintf(pont_arqM, "%d", medUni);
                            fprintf(pont_arqM, "\n/==========/");

                            //fechando arquivo
                            fclose(pont_arqM);
                            printf("Dados gravados com sucesso!\n");
                    }

                printf("Cadastro realizado com sucesso!\n");
                system("pause");
                system("cls");
                break;


                case 4: 
                    fflush(stdin);

                    printf("Cadastro de funcionários: \n");
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
                        printf("\nInforme o CPF do funcionário: ");
                        setbuf(stdin,0);
                        fgets(cpf_func, 10,stdin);
                        system("pause");

                        printf("Informe o nome do funcionário: ");
                        setbuf(stdin,0);
                        fgets(nome_func, 30,stdin);
                        system("pause");

                        printf("Informe a unidade do funcionário 1,2 ou 3: ");
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
                            printf("\nEssa opção não existe. Escolha uma opção válida! \n");
                        }
                        //usando fprintf para armazenar a string no arquivo
                        fprintf(pont_arqF, "\n");
                        fprintf(pont_arqF, "%s", nome_func);
                        fprintf(pont_arqF, "%s", cpf_func);
                        fprintf(pont_arqF, "%d", UniFunc);
                        fprintf(pont_arqF, "\n/==========/");

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

                    printf("\nInforme o seu nome: ");
                        gets(nome);
                    printf("Informe a unidade que o atendeu: ");
                        gets(unidade);

                    printf("Voce teve uma boa experiencia com a unidade?: \n");
                    printf("s ou n: ");
                        scanf("%c",&expc);
                        strlwr(expc);
                    if (expc == 's' || expc== 'n'){

                        if (expc == 's'){
                            pos=pos+1;
                            strcpy (unidade, pos);
                        }
                        if (expc == 'n'){
                            neg=neg+1;
                            strcpy (unidade, neg);
                        }
                    }
                    if (expc !='n' && expc !='s'){
                        printf("Por favor entre somente com s para sim ou n para não");

                    }

                printf("\nFeedback realizado com sucesso! \n");
                system("pause");
                system("cls");
                break;

                case 6:
                    do{
                        exibeRelatorio();
                        printf("Escolha a opção: ");
                            scanf("%d",&opcao);
                        switch(opcao){
                                case 1:fflush(stdin);
                                    printf("Pacientes registrados na unidade 1:%d\n",unipac1);
                                    fflush(stdin);
                                    printf("Pacientes registrados na unidade 2:%d\n",unipac2);
                                    fflush(stdin);
                                    printf("Pacientes registrados na unidade 3:%d\n",unipac3);
                                    fflush(stdin);
                                    printf("Pacientes em total das unidades:%d\n",unipac1+unipac2+unipac3);
                                    system("pause");
                                    system("cls");
                                    break;

                                case 2:
                                        printf("Médicos registrados na unidade 1:%d\n",unidademed1);
                                        printf("Médicos registrados na unidade 2:%d\n",unidademed2);
                                        printf("Médicos registrados na unidade 3:%d\n",unidademed3);
                                        printf("Total de médicos registrados nas unidades: %d",unidademed1+unidademed2+unidademed3);
                                    system("pause");
                                    system("cls");
                                    break;

                                case 3:
                                        printf("Funcionários registrados na unidade 1:%d\n",funcuni1);
                                        printf("Funcionários registrados na unidade 2:%d\n",funcuni2);
                                        printf("Funcionários registrados na unidade 3:%d\n",funcuni3);
                                        printf("Total de funcionários registrados:%d\n",funcuni1+funcuni2+funcuni3);
                                    system("pause");
                                    system("cls");
                                    break;

                                case 4:
                                            maiorPac=unipac1;
                                            if  (unipac2>maiorPac)
                                                maiorPac=unipac2;

                                            if (unipac3>maiorPac)
                                                maiorPac=unipac3;

                                        if (maiorPac=unipac1){
                                        printf("\nUnidade que mais atende pacientes é a unidade 1\n");
                                        }
                                        if (maiorPac=unipac2){
                                        printf("\nUnidade que mais atende pacientes é a unidade 2\n");
                                        }
                                        if (maiorPac=unipac3){
                                        printf("\nUnidade que mais atende pacientes é a unidade 3\n");
                                        }
                                            maiorFunc=funcuni1;
                                            if  (funcuni2>maiorFunc)
                                                maiorFunc=funcuni2;
                                            if (funcuni3>maiorFunc)
                                                maiorFunc=funcuni3;
                                        if (maiorFunc=funcuni1){
                                        printf("\nUnidade com o maior número de funcionários é a unidade 1\n");
                                        }
                                        if (maiorFunc=funcuni2){
                                        printf("\nUnidade com o maior número de funcionários é a unidade 2\n");
                                        }
                                        if (maiorFunc=funcuni3){
                                        printf("\nUnidade com o maior número de funcionários é a unidade 3\n");
                                        }
                                        maiorMed=unidademed1;
                                        if (unidademed2>maiorMed)
                                            maiorMed=unidademed2;

                                        if (unidademed3>maiorMed)
                                        maiorMed=unidademed3;

                                    if (maiorMed=unidademed1){
                                    printf("\nA unidade com o maior número de médicos é a unidade 1\n");
                                    }
                                    if (maiorMed=unidademed2){
                                    printf("\nA unidade com o maior número de médicos é a unidade 2\n");
                                    }
                                    if (maiorMed=unidademed3){
                                    printf("\nA unidade com o maior número de médicos é a unidade 3\n");
                                    }

                                    system("pause");
                                    system("cls");
                                    break;

                            case 5: printf("Valor faturado pela unidade 1: %d\n",valor1*20);
                                    printf("Valor faturado pela unidade 2: %d\n",valor2*20);
                                    printf("Valor faturado pela unidade 3: %d\n",valor3*20);
                                    printf("Valor total de todas unidades: %d\n",valor1*20,valor2*20,valor3*20);
                        case 0:
                                    system("pause");
                                    system("cls");
                                    break;
                    }
                }while (opcao !=0);
                case 0: printf("\nPrograma finalizado! \n");
                        break;

                default: printf("\nEssa opção não existe. Escolha uma opção á! \n");
            }
        }while (opcao != 0);
    }
}

