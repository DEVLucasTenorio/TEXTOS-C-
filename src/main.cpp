#include <Arduino.h>
#include <string.h> //* strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> //! atoi 


void textoTipoC();
void textoTipoString();






void setup()
{
Serial.begin(9600);
  Serial.println();
  textoTipoC();
  textoTipoString();


}


void loop()
{

}




void textoTipoC()
{
/* Texto literal
   Use const char* quando o texto nao sera alterado*/

   const char* cidade = "Sao Paulo"; 
   const char outraCidade[] = "Sao Caetano";
   Serial.println(cidade);
   Serial.println(outraCidade);

   /* Descobrindo o tamanho do texto
      strlen conta quantos caracteres antes do \0*/

      int tamanhoCidade = strlen(cidade);
      int tamanhoOutraCidade = strlen(outraCidade);


      Serial.println(tamanhoOutraCidade);
      Serial.println(tamanhoCidade);

      /*descobrindo o tamanho ocupado */


      int tamanhoVariavel = sizeof(outraCidade);
      int tamanhoPonteiro = sizeof(cidade);



      /*quando usamos o sizeof em uma string sempre retornara
        um byte a mais do que a quantidade de caracteres por 
        causa do \0 que finaliza o texto*/
      Serial.println(tamanhoVariavel);


/*quando usamos o sizeof em ponteiros retorna sempre 4 bytes 
  pois o conteudo dele é um endereco de memoria como 0xff00c245*/
      Serial.println(tamanhoPonteiro);



      /*o caractere \0 é colocado automaticamente quando escrevemos 
        um texto entre aspas duplas " "*/
         
       const char vetorTexto[8] = {'e','d','u','a','r','d','o', '\0'};
      Serial.println(vetorTexto);

      // comparar texto
      const char* cidade1 = "porto alegre";
      const char* cidade2 = "porto alegre";
        

      if(strcmp(cidade1, cidade2) == 0)
      Serial.println("iguais");

      else
      Serial.println("diferentes");

// strcmp analiza a ordem léxica das palavras,
// se a primeira palavra vem antes da segunda o valor retornado sera menor que zero,
// se a primeira palavra vem apos a segunda o retorno sera maior que zero 


//* ====================================================================================
//* TEXTO EDITAVEL COM CHAR
//*====================================================================================

char nomeProfessor[7] = "thiagp";

nomeProfessor[5] = 'o';
Serial.println(nomeProfessor);


//* coiando outro texto para dentr do vetor 
//! cuidado o vetor precisa ter espaco suficiente

strcpy(nomeProfessor, "tadeu");
Serial.println(nomeProfessor);

//* concatenando texto ao final

char frase[40] = "ola ";
strcat(frase, "mundo cruel!");
Serial.println(frase);

//* procurando um caractere no texto 

char* posicaoLetra = strchr(frase, 'm');

if(posicaoLetra != NULL)
{
  Serial.println(posicaoLetra);
}

else
{
Serial.println("nao encontrada");
}

//* convertendo texro numerico para inteiro

char idadeTexto[] = "39";
int idade =  atoi(idadeTexto);

//* montando texto

char buffer[100];
char* local = "sala de aula";
float temperatura = 26.4;
int umidade = 72;

snprintf(buffer, sizeof(buffer), "%s |  temp: %f C  |  umid: %d %%\n\r", local, temperatura, umidade);

Serial.print(buffer);

//* snprintf monta o texto dentro de um vetor de char
//* isso é muito util quando depois voce quer: 
//* -enviar por MQTT
//* -salvar em variavel 
//* -mandar para o display
//* -imprimir na serial

//* ESPECIFICADORES

/*  %d ou %i     int
    %u           unsigned int
    %ld          long
    %lu          unsigned long
    %f           float 
    %e           notacao cientifica
    %g           float, formato mais curto
    %c           char
    %s           char*
    %x ou %X     hexadecimal minusculo/maisuculo
    %o           octal
    %p           ponteiro
    %%           o proprio %
*/    


//* flags, largura e precisao 
/*

   

    %5d        imprime com largura minima de 5, alinhado a direita
    %-2d       imprime com largura minima de 2, alinhado a esquerda
    %04d       completa com zeros ex: 0022
    %+d        sempre mostra o sinal ex: +5
    %.2f       2 casas decimais 
    %4.2f      largura de 4 com 2 casas
    %02x       hexadecimal com 2 digitos 
    %#x        prefixo 0x
    %.3s       só os primeiros 3 caracters da string 
    %*d        largura passada como argumento ex: sprintf (buffer, sizeof(buffer), "%*d, 5, 42")  [42]
    */








    







}


void textoTipoString ()
{
  String nome = "Thiago";
  String curso = "Logica de programacao";
  String mensagem = "ola";

  mensagem = mensagem + "," + nome + "! Bem vindo ao curso de " + curso + ".";

  Serial.println(mensagem);
  int tamanhoMensagem = mensagem.length();
  Serial.printf("Tamanho da String em letra: %u", tamanhoMensagem);

  //* Acessando um caractere em uma posicao especifica
  char primeiraLetra = mensagem.charAt(0);
  Serial.printf("Primeira letra: %c\n\r", primeiraLetra);

  //* Tambem eh possivel acessar colchetes
  char ultimaLetra = mensagem[tamanhoMensagem - 1];
  Serial.printf("Ultima letra: %c\n\r", ultimaLetra);

  //* Procurando um texto dentro da String
  int posicaoTextoProcurado = mensagem.indexOf("curso");
  Serial.printf("A palavra procurada esta na posicao: %d\n\r", posicaoTextoProcurado);
  
  int inicioNomeCurso = posicaoTextoProcurado + 9; //* posicao da palavra curso + 9 posicoes a frente
  
  String nomeCursoTexto = mensagem.substring(inicioNomeCurso, tamanhoMensagem - 1);
  Serial.printf("Nome do curso: %s\n\r", nomeCursoTexto.c_str());

  //* Substituindo um texto dentro da String
  mensagem.replace("Ola,", "Boa tarde!");
  Serial.println(mensagem);

  //* Convertendo tudo em maiusculo
  mensagem.toUpperCase();
  Serial.println(mensagem);

 //* Convertendo tudo em minusculo
  mensagem.toLowerCase();
  Serial.println(mensagem);

  //* Convertendo texto numerico para inteiro
  String textoNumero = "725";
  int numero = textoNumero.toInt();
  Serial.println(numero / 5);

  //* Convertendo String para char* (texto tipo C)
  //* Isso eh util quando alguma biblioteca espera texto tipo C
  char* textoComoChar = (char*) mensagem.c_str();
  Serial.println(textoComoChar);
  

} 