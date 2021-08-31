#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//enviar no arquivo .zip
// o exe nao é pra enviar

typedef struct tdata
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct tendereco
{
    char rua[50];
    int numero;
    char complemento[10];
    char bairro[50];
    char cidade[50];
    char CEP[11];
} TEndereco;

typedef struct tusuario
{
    char nome[15];
    char sobrenome[15];
    char cpf[15]; //usar char
    char identidade[13];
    TEndereco endereco;
    TData data;
    int tipo; // digite 1 para profesor 2 para aluno 3 para funcionario
    char departamento_ou_curso[30];
    double multa;
    int livros;
} TUsuario;

typedef struct TModuloUsuario
{
    int indice; //indica quantos elementos vc tem no vetor e serve para cadastrar novos elementos no vetor
    TUsuario vetor[100];
} TModuloUsuario;
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
typedef struct tlivros
{
    int ISBN;
    char titulo[50];
    char editora[30];
    char local_publicacao[60];
    TData data_publicacao;
    char primeiro_autor[40];
    char segundo_autor[40];
    int numero_edicao;
    int qtd_livros_existentes;
    int qtd_livros_emprestados;
} TLivros;

typedef struct TModuloLivro
{
    int indice;
    TLivros vetor[100];
} TModuloLivros;
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
typedef struct TEmprestimo
{
    int ISBN;
    char CPF[15];
    TData dataEmprestimo;
    TData dataDevolucao;
    TData dataLeitura;
} TEmprestimo;

typedef struct TModuloEmprestimo
{
    int indice;
    TEmprestimo vetor[100];
} TModuloEmprestimo;

//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
int PesquisarUsuario(TUsuario user,TModuloUsuario modUser);
void EfetuarPagamento(TModuloEmprestimo *modulo, TEmprestimo borrow,TModuloUsuario *moduser);
void LerUsuario(TUsuario *user)
{
    printf("\n NOME");
    fflush(stdin);
    fgets(user->nome,15,stdin);

    printf("\n SOBRENOME");
    fflush(stdin);
    fgets(user->sobrenome,15,stdin);

    printf("\n CPF");
    fflush(stdin);
    fgets(user->cpf,15,stdin);

    printf("\n IDENTIDADE");
    fflush(stdin);
    fgets(user->identidade,13,stdin);

    printf("\n RUA");
    fflush(stdin);
    fgets(user->endereco.rua,50,stdin);

    printf("\n NUMERO");
    fflush(stdin);
    scanf("%d",&user->endereco.numero);

    printf("\n COMPLEMENTO");
    fflush(stdin);
    fgets(user->endereco.complemento,30,stdin);


    printf("\n BAIRRO");
    fflush(stdin);
    fgets(user->endereco.bairro,50,stdin);


    printf("\n CIDADE");
    fflush(stdin);
    fgets(user->endereco.cidade,30,stdin);


    printf("\n CEP");
    fflush(stdin);
    fgets(user->endereco.CEP,11,stdin);


    printf("\n DATA DE NASCIMENTO:");
    printf("\n DIA");
    fflush(stdin);
    scanf("%d",&user->data.dia);

    printf("\n MES");
    fflush(stdin);
    scanf("%d",&user->data.mes);

    printf("\n ANO");
    fflush(stdin);
    scanf("%d",&user->data.ano);

    //digite 1 para profesor 2 para aluno 3 para funcionario
    printf("\nTIPO DE USUARIO: 1 para professor, 2 para aluno, 3 para funcionario");
    fflush(stdin);
    scanf("%d",&user->tipo);

    printf("\nDEPARTAMENTO OU CURSO");
    fflush(stdin);
    fgets(user->departamento_ou_curso,30,stdin);
    user->multa=0;
    user->livros=0;
}
void LerLivro(TLivros *book)
{

    printf("\nISBN(Apenas numeros): ");
    fflush(stdin);
    scanf("%d",&book->ISBN);

    printf("\nTITULO");
    fflush(stdin);
    fgets(book->titulo,50,stdin);

    printf("\nEDITORA");
    fflush(stdin);
    fgets(book->editora,30,stdin);

    printf("\nLOCAL DE PUBLICACAO");
    fflush(stdin);
    fgets(book->local_publicacao,60,stdin);

    printf("\nDATA DE PUBLICACAO: DIA");
    fflush(stdin);
    scanf("%d",&book->data_publicacao.dia);

    printf("\nDATA DE PUBLICACAO: MES");
    fflush(stdin);
    scanf("%d",&book->data_publicacao.mes);

    printf("\nDATA DE PUBLICACAO: ANO");
    fflush(stdin);
    scanf("%d",&book->data_publicacao.ano);

    printf("\nPRIMEIRO AUTOR");
    fflush(stdin);
    fgets(book->primeiro_autor,50,stdin);

    printf("\nSEGUNDO AUTOR AUTOR");
    fflush(stdin);
    fgets(book->segundo_autor,50,stdin);

    printf("\nNUMERO DA EDICAO");
    fflush(stdin);
    scanf("%d",&book->numero_edicao);

    printf("\nQUANTIDADE DE LIVROS EXISTENTES");
    fflush(stdin);
    scanf("%d",&book->qtd_livros_existentes);

    printf("\nQUANTIDADE DE LIVROS EMPRESTADOS");
    fflush(stdin);
    scanf("%d",&book->qtd_livros_emprestados);



}
TData CalcularDataEntrega(TData data_emprestimo);
void LerEmprestimo(TEmprestimo *give)
{
    printf("\nISBN");
    fflush(stdin);
    scanf("%d",&give->ISBN);

    printf("\nCPF");
    fflush(stdin);
    fgets(give->CPF,15,stdin);

    printf("\nDATA DE EMPRESTIMO: ");
    printf("\nDIA");
    fflush(stdin);
    scanf("%d",&give->dataEmprestimo.dia);

    printf("\nMES");
    fflush(stdin);
    scanf("%d",&give->dataEmprestimo.mes);

    printf("\nANO");
    fflush(stdin);
    scanf("%d",&give->dataEmprestimo.ano);

    TData data;
    data.dia = give->dataEmprestimo.dia;
    data.mes = give->dataEmprestimo.mes;
    data.ano = give->dataEmprestimo.ano;
  give->dataDevolucao = CalcularDataEntrega(data);

}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
void IniciarModuloLivros(TModuloLivros *startL)
{
    startL->indice=0;
}
void IniciarModuloUsuario(TModuloUsuario *startU)
{
    startU->indice=0;
}
void IniciarModuloEmprestimo(TModuloEmprestimo *startE)
{
    startE->indice=0;
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
void ImprimirUsuario(TUsuario user)
{
    printf("\nNOME: %s",user.nome);
    printf("\nSOBRE-NOME: %s",user.sobrenome);
    printf("\nCPF: %s",user.cpf);
    printf("\nIDENTIDADE: %s",user.identidade);

    printf("\nENDERECO:");
    printf("\nRUA: %s ",user.endereco.rua);
    printf("\nNUMERO: %d",user.endereco.numero);
    printf("\nCOMPLEMENTO: %s",user.endereco.complemento);
    printf("\nBAIRRO: %s",user.endereco.bairro);
    printf("\nCIDADE: %s",user.endereco.cidade);
    printf("\nCEP: %s",user.endereco.CEP);

    printf("\n--------------DATA:------------------");
    printf("\n%d/%d/%d",user.data.dia,user.data.mes,user.data.ano);

    printf("\nMulta: R$ %.2f",user.multa);
//digite 1 para profesor 2 para aluno 3 para funcionario
    printf("\nTIPO:");
    if(user.tipo==2)
    {
        printf("ALUNO");
    }
    else if(user.tipo == 1)
    {
        printf("PROFESSOR");
    }
    else if(user.tipo == 3)
    {
        printf("FUNCIONARIO");
    }


}

void ImprimirLivro(TLivros book)
{

    printf("\nISBN: %d",book.ISBN);
    printf("\nTITULO: %s ",book.titulo);
    printf("\nEDITORA: %s",book.editora);
    printf("\nLOCAL DE PUBLICACAO: %s",book.local_publicacao);

    printf("\nDATA:");
    printf("%d/%d/%d",book.data_publicacao.dia,book.data_publicacao.mes,book.data_publicacao.ano);

    printf("\nPRIMEIRO AUTOR: %s",book.primeiro_autor);
    printf("\nSEGUNDO AUTOR: %s",book.segundo_autor);
    printf("\nNUMERO DA EDICAO: %d",book.numero_edicao);
    printf("\nQUANTIDADE DE LIVROS EXISTENTES: %d",book.qtd_livros_existentes);
    printf("\nQUANTIDADE DE LIVROS EMPRESTADOS: %d",book.qtd_livros_emprestados);
}
void ImprimirEmprestimio(TEmprestimo give)
{

    printf("ISBN: %d",give.ISBN);
    printf("CPF: %s",give.CPF);
    printf("\nData de Emprestimo: ");
    printf("  %d/%d/%d",give.dataEmprestimo.dia,give.dataEmprestimo.mes,give.dataEmprestimo.ano);


}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
void InserirUsuario(TModuloUsuario *muser,TUsuario user)
{

    muser->vetor[muser->indice]=user;
    muser->indice++;
}
void InserirLivro(TModuloLivros *Mbook,TLivros book)
{

    Mbook->vetor[Mbook->indice] = book;
    Mbook->indice++;
}
int PesquisarLivro(TLivros book,TModuloLivros modLivro);
void InserirEmprestimo(TModuloEmprestimo *Mgive,TEmprestimo give,TModuloLivros *modbook,TModuloUsuario *moduser)
{

    TLivros livro;
    TUsuario user;
    strcpy(user.cpf,give.CPF);
    livro.ISBN=give.ISBN;
   int b = PesquisarUsuario(user,*moduser); //algum problema aki!!!!!!!!!!!!!!! b.o

   int a = PesquisarLivro(livro,*modbook);





    if(a==-1){
        printf("O ISBN digitado nao bate com nenhum livro do banco de dados!");
        }
    if(b==-1){
       printf("O CPF digitado nao bate com nenhum usuario do banco de dados!!");
            }

    if(b!=-1 && a!=-1){

   /* if(moduser->vetor[b].tipo == 1 && moduser->vetor[b].livros<5) //1pra professor e 2 para aluno
    {
        moduser->vetor[b].livros++;
    }else if(moduser->vetor[b].livros>=5)
       {
           printf("\nVoce nao pode pegar mais de 5 livros!");
       }
    }else if(moduser->vetor[b].tipo == 2) //1pra professor e 2 para aluno
    {
       if(moduser->vetor[b].livros<3)
       {
           moduser->vetor[b].livros++;
       }else if(moduser->vetor[b].livros>=3)
       {
           printf("Voce nao pode pegar mais de 3 livros!");
       }*/
    if(modbook->vetor[a].qtd_livros_existentes>modbook->vetor[a].qtd_livros_emprestados){
    modbook->vetor[a].qtd_livros_emprestados++;
///// digite 1 para profesor 2 para aluno 3 para funcionario
         if(moduser->vetor[b].tipo == 1 && moduser->vetor[b].livros<5)
         {
             if(moduser->vetor[b].multa<=0)
             {
             Mgive->vetor[Mgive->indice] = give;
             Mgive->indice++;
             moduser->vetor[b].livros++;
             }else
             {
                 printf("\nVoce nao pode pegar livros enquanto nao quitar sua multa!!\nMulta Atual: R$ %.2f",moduser->vetor[b].multa);
             }

         }else if(moduser->vetor[b].tipo == 1 && moduser->vetor[b].livros>=5)
         {
             printf("\nVoce nao pode pegar mais de 5 livros!");
         }
          if(moduser->vetor[b].tipo == 2 && moduser->vetor[b].livros<3)
         {
             if(moduser->vetor[b].multa<=0)
             {
             Mgive->vetor[Mgive->indice] = give;
             Mgive->indice++;
             moduser->vetor[b].livros++;
             }else
             {
              printf("\nVoce nao pode pegar livros enquanto nao quitar sua multa!!\nMulta Atual: R$ %.2f",moduser->vetor[b].multa);
             }

         }else if (moduser->vetor[b].tipo == 2 && moduser->vetor[b].livros>=3)
         {
             printf("\nVoce nao pode pegar mais de 3 livros!");
         }

    }else
    {
        printf("\nEsse livro nao esta disponiivel no momento!");
    }

    }
}


int PesquisarLivro(TLivros book,TModuloLivros modLivro)
{
    int i;
    for(i=0; i<modLivro.indice; i++)
    {
        if(modLivro.vetor[i].ISBN==book.ISBN)
        {
            return i;
        }
    }
    return -1;
}
int PesquisarUsuario(TUsuario user,TModuloUsuario modUser)
{
    int i;
    for(i=0; i<=modUser.indice; i++)
    {

        if(strcmp(user.cpf,modUser.vetor[i].cpf)==0)
        {
            return i;
        }
    }
    return -1;
}
int PesquisarEmprestimo(TEmprestimo give,TModuloEmprestimo modgive)
{
    int i;
    for(i=0; i<modgive.indice; i++)
    {
        if(give.ISBN==modgive.vetor[i].ISBN)
        {
            if(strcmp(give.CPF,modgive.vetor[i].CPF)==0)
            {
                if(give.dataEmprestimo.dia==modgive.vetor[i].dataEmprestimo.dia)
                {
                    if(give.dataEmprestimo.mes==modgive.vetor[i].dataEmprestimo.mes)
                    {
                        if(give.dataEmprestimo.ano==modgive.vetor[i].dataEmprestimo.ano)
                        {
                            return i;
                        }
                    }
                }
            }
        }
    }
    return -1;

}
void ImprimirgeralUsuario(TModuloUsuario moduser)
{
    int i;
    for(i=0; i<moduser.indice; i++)
    {
        ImprimirUsuario(moduser.vetor[i]);
    }
}
void ImprimirGeralLivro(TModuloLivros modbook)
{
    int i;
    for(i=0; i<modbook.indice; i++)
    {
        ImprimirLivro(modbook.vetor[i]);
    }
}
void ImprimirGeralEmprestimo(TModuloEmprestimo modgive)
{
    int i;
    for(i=0; i<modgive.indice; i++)
    {
        ImprimirEmprestimio(modgive.vetor[i]);
    }
}

void ExcluirUsuario(TUsuario user,TModuloUsuario *moduser)
{
    int a = PesquisarUsuario(user,*moduser);
    if(a>=0)
    {
        while(a<moduser->indice)
        {
            moduser->vetor[a]=moduser->vetor[a+1];
            a++;
        }
        moduser->indice--;
    }
    else
    {
        printf("\nESSE USUARIO NAO EXISTE!");
    }
}
void ExcluirLivro(TLivros book,TModuloLivros *modbook)
{
    int a = PesquisarLivro(book,*modbook);
    if(a>=0)
    {
        while(a<modbook->indice)
        {
            modbook->vetor[a]=modbook->vetor[a+1];
            a++;
        }
        modbook->indice--;
    }
    else
    {
        printf("\nESSE LIVRO NAO EXISTE!");
    }
}
void ExcluirEmprestimo(TEmprestimo give,TModuloEmprestimo *modgive)
{
    int a = PesquisarEmprestimo(give,*modgive);
    if(a>=0)
    {
        while(a<modgive->indice)
        {
            modgive->vetor[a]=modgive->vetor[a+1];
            a++;
        }
        modgive->indice--;
    }
    else
    {
        printf("\nESSE EMPRESTIMO NAO EXISTE!");
    }
}
void AlterarUsuario(TUsuario user,TModuloUsuario *moduser)
{
    int a = PesquisarUsuario(user,*moduser);
    if (a>=0)
    {
        printf("\nFaca as alteracos:");
        LerUsuario(&moduser->vetor[a]);

    }
    else
    {
        printf("\nUsuario nao encontrado!");
    }

}
void AlterarLivro(TLivros book,TModuloLivros *modbook)
{
    int a = PesquisarLivro(book,*modbook);
    if (a>=0)
    {
        printf("\nFaca as alteracoes: ");
        LerLivro(&modbook->vetor[a]);
    }
    else
    {
        printf("\nLivro nao encontrado!");
    }

}
void AlterarEmprestimo(TEmprestimo give,TModuloEmprestimo *modgive)
{
    int a = PesquisarEmprestimo(give,*modgive);
    if (a>=0)
    {
        LerEmprestimo(&modgive->vetor[a]);
    }
    else
    {
        printf("\nEMPRESTIMO INEXISTENTE");
    }
}
void MSG_SUBMENU(int nummod)
    {
        if(nummod!=3)
        {
          printf("\n--------------------------MODULO %d---------------------------",nummod);
        printf("\n\t1. INSERIR");
        printf("\n\t2. PESQUISAR");
        printf("\n\t3. ALTERAR");
        printf("\n\t4. EXCLUIR");
        printf("\n\t5. RELATORIO GERAL");
        printf("\n\t6. SAIR");
        }
        else if(nummod==3)
        {
            printf("\n--------------------------MODULO %d---------------------------",nummod);
        printf("\n\t1. INSERIR");
        printf("\n\t2. PESQUISAR");
        printf("\n\t3. ALTERAR");
        printf("\n\t4. EXCLUIR");
        printf("\n\t5. RELATORIO GERAL");
        printf("\n\t6. EFETUAR PAGAMENTO");
        printf("\n\t7. DAR BAIXA");
        printf("\n\t8. SAIR");
        }
    }
void MSG_MENU()
    {
        printf("\n--------------------------MENU---------------------------");
        printf("\n\t1. MODULO 1 - LIVRO");
        printf("\n\t2. MODULO 2 - USUARIO");
        printf("\n\t3. MODULO 3 - EMPRESTIMO");
        printf("\n\t4. SAIR");
    }
 void SubmenuModulo1(TModuloLivros *modbook,TLivros book)
    {
        system("cls");
        MSG_SUBMENU(1);
        int opcao;
        do
        {
            printf("\n\tEscolha uma Opcao:");
            fflush(stdin);
            scanf("%d",&opcao);
            int t = modbook->indice;
            switch (opcao)
            {
            case 1:
                LerLivro(&book);
                InserirLivro(modbook,book);
                if(t+1==modbook->indice)
                {
                    printf("\t\tLivro inserido com sucesso!");
                }
                else
                {
                    printf("falha ao inserir livro");
                }

                break;
            case 2:
                printf("\n\tDigite o ISBN do livro que deeseja encontrar: ");
                fflush(stdin);
                scanf("%d",&book.ISBN);
                int indice = PesquisarLivro(book,*modbook);
                if(indice!=-1)
                {
                    ImprimirLivro(modbook->vetor[indice]);
                }
                else
                {
                    printf("Livro nao encontrado ou inexistente!");
                }
                break;
            case 3:
                printf("\n\tDigite o ISBN do livro que deeseja alterar: ");
                fflush(stdin);
                scanf("%d",&book.ISBN);
                AlterarLivro(book,modbook);
                ImprimirGeralLivro(*modbook);
                break;
            case 4:
                printf("\n\tDigite o ISBN do livro que deeseja excluir: ");
                fflush(stdin);
                scanf("%d",&book.ISBN);
                ExcluirLivro(book,modbook);
                int teste = PesquisarLivro(book,*modbook);
                if(teste==-1)
                {
                    printf("\nLivro Excluido com sucesso!");
                }
                break;
            case 5:
               ImprimirGeralLivro(*modbook);
                break;
            case 6:
                printf("\n>>>>>>>>>>>>SAINDO DO MODULO 1<<<<<<<<<<<<<<<<,");
                break;
            default:
                printf("Digite uma opcao valida!!");
                system("PAUSE"); //BURRO! KKKKKK
            }
        }
        while(opcao!=6);
    }

     void SubmenuModulo2(TModuloUsuario *moduser,TUsuario user)
    {
        MSG_SUBMENU(2);
        int opcao;
        do
        {
            printf("\n\tEscolha uma Opcao:");
            fflush(stdin);
            scanf("%d",&opcao);
            int t = moduser->indice;
            switch (opcao)
            {
            case 1:
                LerUsuario(&user);
                InserirUsuario(moduser,user);
                if(t+1==moduser->indice)
                {
                    printf("\t\tUsuario inserido com sucesso!");
                }
                else
                {
                    printf("falha ao inserir usuario");
                }

                break;
            case 2:
                printf("\n\tDigite o CPF do usuario que deeseja encontrar: ");
                fflush(stdin);
                fgets(user.cpf,15,stdin);
                int indice = PesquisarUsuario(user,*moduser);
                if(indice!=-1)
                {
                    ImprimirUsuario(moduser->vetor[indice]);
                }
                else
                {
                    printf("Usuario nao encontrado ou inexistente!");
                }
                break;
            case 3:
                printf("\n\tDigite o CPF do usuario que deeseja alterar: ");
                fflush(stdin);
                fgets(user.cpf,15,stdin);
                AlterarUsuario(user,*&moduser);
                ImprimirgeralUsuario(*moduser);
                break;
            case 4:
                printf("\n\tDigite o CPF do usuario que deeseja excluir: ");
                fflush(stdin);
                fgets(user.cpf,15,stdin);
                ExcluirUsuario(user,*&moduser);
                int teste = PesquisarUsuario(user,*moduser);
                if(teste==-1)
                {
                    printf("\nUsuario Excluido com sucesso!");
                }
                break;
            case 5:
                ImprimirgeralUsuario(*moduser);
                break;
            case 6:
                printf("\n>>>>>>>>>>>>SAINDO DO MODULO 2<<<<<<<<<<<<<<<<,");
                break;
            default:
                printf("Digite uma opcao valida!!");
                system("PAUSE"); //BURRO! KKKKKK
            }
        }
        while(opcao!=6);
    }
void DarBaixaEmprestimo(TModuloEmprestimo *modgive,TEmprestimo give,TModuloUsuario *moduser);
    void SubmenuModulo3(TModuloEmprestimo *modgive, TEmprestimo give,TModuloLivros modulolivro,TModuloUsuario *moduser)
    {
        MSG_SUBMENU(3);
        int opcao;
        do
        {
            printf("\n\tEscolha uma Opcao:");
            fflush(stdin);
            scanf("%d",&opcao);
            int t = modgive->indice;
            switch (opcao)
            {
            case 1:
                LerEmprestimo(&give);

                InserirEmprestimo(modgive,give,&modulolivro,moduser);

                if(t+1==modgive->indice)
                {
                    printf("\t\tEmprestimo realizado com sucesso!");
                }
                else
                {
                    printf("falha ao realizar emprestimo");
                }

                break;
            case 2:
                printf("\n\tDigite o CPF do emprestimo que deseja encontrar: ");
                fflush(stdin);
                fgets(give.CPF,15,stdin);

                printf("\n\tDigite o ISBN do emprestimo que deseja encontrar: ");
                fflush(stdin);
                scanf("%d",&give.ISBN);

                printf("\n Digite a data de realizacao do emprestimo que deseja encontrar:");
                printf("\nDIA ");
                fflush(stdin);
                scanf("%d",&give.dataEmprestimo.dia);


                printf("\nMES ");
                fflush(stdin);
                scanf("%d",&give.dataEmprestimo.dia);

                printf("\nANO ");
                fflush(stdin);
                scanf("%d",&give.dataEmprestimo.dia);


                int indice = PesquisarEmprestimo(give,*modgive);
                if(indice!=-1)
                {
                    ImprimirEmprestimio(modgive->vetor[indice]);
                }
                else
                {
                    printf("Emprestimo nao encontrado ou inexistente!");
                }
                break;
            case 3:
                printf("\n\tDigite o CPF do emprestimo que deseja alterar: ");
                fflush(stdin);
                fgets(give.CPF,15,stdin);

                printf("\n\tDigite o ISBN do emprestimo que deseja alterar: ");
                fflush(stdin);
                scanf("%d",&give.ISBN);

                printf("\n Digite a data de realizacao do emprestimo que deseja alterar:");
                printf("\nDIA ");
                fflush(stdin);
                scanf("%d",&give.dataEmprestimo.dia);


                printf("\nMES ");
                fflush(stdin);
                scanf("%d",&give.dataEmprestimo.dia);

                printf("\nANO ");
                fflush(stdin);
                scanf("%d",&give.dataEmprestimo.dia);
                printf("\nfaca as alteracoes:\n");
                AlterarEmprestimo(give,modgive);
                ImprimirGeralEmprestimo(*modgive);
                break;
            case 4:
                printf("\n\tDigite o CPF do emprestimo que deseja excluir: ");
                fflush(stdin);
                fgets(give.CPF,15,stdin);

                printf("\n\tDigite o ISBN do emprestimo que deseja excluir: ");
                fflush(stdin);
                scanf("%d",&give.ISBN);

                printf("\n Digite a data de realizacao do emprestimo que deseja excluir:");
                printf("\nDIA ");
                fflush(stdin);
                scanf("%d",&give.dataEmprestimo.dia);


                printf("\nMES ");
                fflush(stdin);
                scanf("%d",&give.dataEmprestimo.dia);

                printf("\nANO ");
                fflush(stdin);
                scanf("%d",&give.dataEmprestimo.dia);


                ExcluirEmprestimo(give,modgive);
                int teste = PesquisarEmprestimo(give,*modgive);
                if(teste==-1)
                {
                    printf("\nEmprestimo Excluido com sucesso!");
                }
                break;
            case 5:
                ImprimirGeralEmprestimo(*modgive);
                break;
            case 6:
                printf("\n-------Efetuar Pagamento---------");
                printf("\nDigite o CPF:");
                fflush(stdin);
                fgets(give.CPF,14,stdin);
                printf("\nDigite o ISBN:");
                fflush(stdin);
                scanf("%d",&give.ISBN);
                TUsuario auxiliar;
               strcpy(auxiliar.cpf,give.CPF);
                int t = PesquisarUsuario(auxiliar,*moduser);
                give.dataEmprestimo.dia = modgive->vetor[t].dataEmprestimo.dia;
                give.dataEmprestimo.mes = modgive->vetor[t].dataEmprestimo.mes;
                give.dataEmprestimo.ano = modgive->vetor[t].dataEmprestimo.ano;
                EfetuarPagamento(modgive,give,moduser);
                break;
                case 7:
            printf("\n\t -------DAR BAIXA--------------------------\n\n");
            printf("Insira o CPF: ");
            fflush(stdin);
            fgets(give.CPF,14,stdin);
            printf("Insira o ISBN do livro: ");
            fflush(stdin);
            scanf("%d",&give.ISBN);
            printf("Insira a data do emprestimo:\nDia");
            fflush(stdin);
            scanf("%d",&give.dataEmprestimo.dia);
            printf("\nMes");
            fflush(stdin);
            scanf("%d",&give.dataEmprestimo.mes);
            printf("\nAno");
            fflush(stdin);
            scanf("%d",&give.dataEmprestimo.ano);

            indice = PesquisarEmprestimo(give,*modgive);
            if(indice!=-1)
            {
               DarBaixaEmprestimo(modgive,give,moduser);
            }else
            {
                printf("\nEmprestimo nao encontrado!");
            }

            break;
            case 8:
                printf("\n>>>>>>>>>>>>SAINDO DO MODULO 2<<<<<<<<<<<<<<<<,");
                break;
            default:
                printf("Digite uma opcao valida!!");
                system("PAUSE"); //BURRO! KKKKKK
            }
        }
        while(opcao!=8);
    }
    int qtdDiasDeCadaMes(int mes);
    TData CalcularDataEntrega(TData data_emprestimo)
    {
        TData dataEntrega;
     int ultimodia = qtdDiasDeCadaMes(data_emprestimo.mes);
        if(data_emprestimo.dia+14<=ultimodia)
        {
            dataEntrega.dia = data_emprestimo.dia+14;
            dataEntrega.mes = data_emprestimo.mes;
            dataEntrega.ano = data_emprestimo.ano;
            return dataEntrega;
        }else if(data_emprestimo.dia+14>ultimodia && data_emprestimo.mes!=12)
        {
            int i = ultimodia - data_emprestimo.dia;
            int j = 14 - i;
            dataEntrega.dia = j;
            dataEntrega.mes=data_emprestimo.mes++;
            dataEntrega.ano=data_emprestimo.ano;
            return dataEntrega;
        }else if(data_emprestimo.dia+14>ultimodia && data_emprestimo.mes==12)
        {
           int i = ultimodia - data_emprestimo.dia;
            int j = 14 - i;
            dataEntrega.dia = j;
            dataEntrega.mes=1;
            dataEntrega.ano=data_emprestimo.ano++;
            return dataEntrega;
        }
    }

    int qtdDiasDeCadaMes(int mes)
    {
     switch (mes)
     {
     case 1:
        return 31;
        break;
     case 2:
        return 28;
        break;
     case 3:
        return 31;
        break;
     case 4:
        return 30;
        break;
     case 5:
        return 31;
        break;
     case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
     case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
     case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
     case 12:
        return 31;
        break;
     }
    }
    int qtdDiasAcumulados(int mes)
    {
        int a=0;
         switch (mes)
        {
        case 12:
            a+=31;
        case 11:
            a+=30;
        case 10:
            a+=31;
        case 9:
            a+=30;
        case 8:
            a+=31;
        case 7:
            a+=31;
        case 6:
            a+=30;
        case 5:
            a+=31;
        case 4:
            a+=30;
        case 3:
            a+=31;
        case 2:
            a+=28;
        case 1:
            a+=31;
            break;

        }
        return a;
    }
    void CalcularMulta(TUsuario *user,TEmprestimo give)
    {
       give.dataDevolucao = CalcularDataEntrega(give.dataEmprestimo);
        int mesDevolucao = qtdDiasAcumulados(give.dataDevolucao.mes);
        int mesLeitura = qtdDiasAcumulados(give.dataLeitura.mes);
   // printf("\naki no calcular multa blz");
        int dias = (give.dataDevolucao.ano - give.dataLeitura.ano)*365 + (mesDevolucao - mesLeitura)
        + (give.dataDevolucao.dia-give.dataLeitura.dia);
        printf("\n\ndias = %d",dias);
    if(dias<0)
    {
        dias=dias*-1;
        int multa = 2 * dias;
        int k,valor;
        printf("\nO valor da multa e de R$ %d,00",multa);
        printf("\t\n Digite 1 para quitar a divida ou 0 para arquivar: ");
        fflush(stdin);
        scanf("%d",&k);
        if(k==1)
        {
            printf("\t\nDigite o valor a quitar: ");
            fflush(stdin);
            scanf("%d",&valor);
            multa=multa-valor;
            user->multa+=multa;
            double c = user->multa;
            printf("\nValor quitado: %d,00\nValor atual da multa: %.2f",valor,c);
        }else
        {
            user->multa+=multa;
            printf("\nMulta arquivada!");
        }

    }
    }
    void DarBaixaEmprestimo(TModuloEmprestimo *modgive,TEmprestimo give,TModuloUsuario *moduser)
    {
        printf("\t\nInsira a data de leitura(hoje): ");
        printf("\nDIA: ");
        fflush(stdin);
        scanf("%d",&give.dataLeitura.dia);
        printf("\nMES: ");
        fflush(stdin);
        scanf("%d",&give.dataLeitura.mes);
        printf("\nANO: ");
        fflush(stdin);
       scanf("%d",&give.dataLeitura.ano);
        TUsuario usuario;
        strcpy(usuario.cpf,give.CPF);
        int indice = PesquisarUsuario(usuario,*moduser);
        moduser->vetor[indice].livros--;
        printf("\nate aki blz");
        CalcularMulta(&moduser->vetor[indice],give);

    }
void EfetuarPagamento(TModuloEmprestimo *modulo, TEmprestimo borrow,TModuloUsuario *moduser)
{
    TUsuario user;
    strcpy(user.cpf,borrow.CPF);
  int a = PesquisarUsuario(user,*moduser);
  double y = moduser->vetor[a].multa;
  double p;
  int b;
  if(a!=-1){
  printf("\nMulta atual: R$ %.2f\nDIgiteo valor que deseja quitar: ",moduser->vetor[a].multa);
  fflush(stdin);
  scanf("%d",&b);
  double x = moduser->vetor[a].multa - b;
  moduser->vetor[a].multa= x;
  printf("Multa atualizada: R$ %.2f",x);
  }else
  {
      printf("\nusuario nao encontrado");
  }

}

int main()
{
    TUsuario usuario;
    TLivros livro;
    TEmprestimo emprestimo;
    TModuloUsuario moduloUsuario;
    TModuloLivros moduloLivro;
    TModuloEmprestimo moduloEmprestimo;

    IniciarModuloLivros(&moduloLivro);
    IniciarModuloEmprestimo(&moduloEmprestimo);
    IniciarModuloUsuario(&moduloUsuario);

    int parar=1;
    int indice;

void MenuPrincipal()
{
    int opcao=0;

    do
    {
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            SubmenuModulo1(&moduloLivro,livro);
            break;
        case 2:
            SubmenuModulo2(&moduloUsuario,usuario);
            break;
        case 3:
            SubmenuModulo3(&moduloEmprestimo,emprestimo,moduloLivro,&moduloUsuario);
            break;

        case 4:
            printf(">>>>>>>>>>>>>>>>Saindo do programa!...<<<<<<<<<<<<<<<<");
            parar=0;
            system("PAUSE");
            break;
        default:
            printf("Digite uma opcao valida!!");
            system("PAUSE"); //BURRO! KKKKKK
        }
    }
    while(opcao=!4);
}
// ------------------------VAMOS COMEÇAR O MENU-----------------------------
while(parar==1)
{
  MenuPrincipal();
}




    return 0;
}
