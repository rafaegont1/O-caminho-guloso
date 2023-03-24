<h1>O caminho guloso</h1>

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
</div>

<h2>Proposta</h2>

<p align="justify">
    No decorrer do curso, é muito provável que todos precisaram, em algum momento, trabalhar com o conceito de caminhamento em matrizes de forma gulosa, ou seja, optando por um dado caminho e não mais olhando para trás ou para decisões já tomadas. Neste trabalho vamos caminhar por um conjunto de matrizes fornecidas como entrada, objetivando encontrar o maior valor final segundo um conjunto de regras preestabelecidas, objetivando com isso: <b>(1)</b> revisar os conceitos de programação básica com matrizes, <b>(2)</b> iniciar um cenário de questionamentos para identificar se realmente a implementação realizada é a forma otimizada e; <b>(3)</b> iniciar uma busca para uma boa estruturação de código.
</p>

<h2>Explicação</h2>

<p align="justify">
    Os algoritmos gulosos, de uma maneira geral, buscam a melhor opção disponível no momento, a fim de conseguir atingir uma solução ótima global. Sem se importar com as consequências das decisões tomadas, os algoritmos gulosos nunca reconsideram decisões já feitas, os tornando bastante eficientes, devido a sua simplicidade.
</p>

<p align="justify">
    O algoritmo deste programa é considerado guloso porque ele sempre busca os elementos que possuem maior valor, sem refazer suas decisões. No arquivo <i>main.c</i>, o programa tenta abrir o arquivo "input.data" no diretório atual (<b>linha 6</b>). Caso a tentativa falhe, o programa fecha com <i>exit code</i> 1 (<b>linhas 8-11</b>). Caso contrário, a primeira string do programa é lida e armazenada como o tamanho da matriz (<b>linha 13</b>). O tamanho é então usado para alocar a memória dinâmica para o ponteiro <i>mat</i> (<b>linha 15</b>).
</p>

<p align="justify">
    Para mostrar um exemplo de execução do programa, foi utilizado o arquivo <i>input.data</i>. A matriz testada, de tamanho quadrado quarto por quatro (4x4), possuia apenas números positivos. É importante destacar que a matriz não deverá apresentar nenhum valor zero, pois este valor será utilizado para orientar o algoritmo quando este for percorrer a matriz. A entrada utilizada foi a seguinte:
</p>

<table align="center">
    <tr>
        <td align="center">478</td>
        <td align="center">664</td>
        <td align="center">153</td>
        <td align="center">268</td>
    </tr>
    <tr>
        <td align="center">903</td>
        <td align="center">762</td>
        <td align="center">253</td>
        <td align="center">590</td>
    </tr>
    <tr>
        <td align="center">707</td>
        <td align="center">409</td>
        <td align="center">87</td>
        <td align="center">351</td>
    </tr>
    <tr>
        <td align="center">485</td>
        <td align="center">564</td>
        <td align="center">114</td>
        <td align="center">584</td>
    </tr>
</table>

<p align="justify">
    Em seguida, o programa entra em um loop (<b>linhas 17-27</b>) que continua até que a leitura do arquivo chegue ao fim. Os valores das matrizes foram lidos e atribuídos aos elementos da matriz (<b>linha 20</b>). Após ler a primeira matriz e, caso o arquivo não tenha chegado ao fim, os valores da nova matriz são sobrescritos na matriz <i>mat</i>.
</p>

<p align="justify">
    No arquivo <i>funcoes.c</i>, a função <i>greedyAlg</i> faz a verificação da matriz a partir de um <i>loop</i> que continua até que o programa chegue até a última linha (<b>linhas 11-39</b>). O algoritmo começa a verificar a matriz a partir do elemento disposto na primeira coluna da primeira linha. Com isso, ele procura verificar qual é o maior valor dentre os elementos das colunas próxima e anterior, para a linha de baixo e para as diagonais para baixo. O programa avalia qual é o maior valor dentre cinco direções:
</p>

<ul>
    <li>a próxima coluna</li>
    <li>a coluna anterior</li>
    <li>a linha de baixo</li>
    <li>as duas diagonais para baixo</li>
</ul>

<table align="center">
    <tr>
        <td align="center">&#x21D0;</td>
        <td align="center"></td>
        <td align="center">&#x21D2;</td>
    </tr>
    <tr>
        <td align="center">&#x21D9;</td>
        <td align="center">&#x21D3;</td>
        <td align="center">&#x21d8;</td>
    </tr>
</table>

<p align="justify">
    Determinado o maior valor, o algoritmo move para a direção de maior valor, marcando o valor anterior como zero (<b>linha 35</b>), para que o algoritmo não possa voltar a esse elemento.
</p>

<p align="justify">
    Em seguida, é chamada a função <i>joystick</i> (<b>linhas 50-70</b>), onde um <i>switch case</i> define, a partir de um argumento <i>char</i> passado para a função, para qual direção o algoritmo deve se mover.
</p>

<p align="justify">
    Foram acrescentadas duas condições (<b>linhas 16-26</b>), a fim de garantir que o programa não exceda os limites da matriz, causando assim um erro na execução do programa. As condições são:
</p>

<ul>
    <li>Se a variável <i>j</i> for igual a 0, o programa não tenta acessar uma coluna anterior</li>
    <li>Se a variável <i>i + 1</i> for igual a variável <i>mat_sz</i>, o programa não tenta acessar a próxima coluna</li>
</ul>

<p align="justify">
    Assim que o algoritmo chega a última linha da matriz, é realizado mais um <i>loop</i> para que o algoritmo chegue até a última coluna (<b>linhas 41-45</b>). Portanto, o programa apenas move para a próxima coluna até o fim do <i>loop</i>. Ao fim, a função retorna a soma do caminho. Segue abaixo o caminho percorrido pelo algoritmo:
</p>

<table align="center">
    <tr>
        <td align="center">$\colorbox{olive}{478}$</td>
        <td align="center">664</td>
        <td align="center">153</td>
        <td align="center">268</td>
    </tr>
    <tr>
        <td align="center">$\colorbox{olive}{903}$</td>
        <td align="center">$\colorbox{olive}{762}$</td>
        <td align="center">253</td>
        <td align="center">590</td>
    </tr>
    <tr>
        <td align="center">$\colorbox{olive}{707}$</td>
        <td align="center">409</td>
        <td align="center">87</td>
        <td align="center">351</td>
    </tr>
    <tr>
        <td align="center">485</td>
        <td align="center">$\colorbox{olive}{564}$</td>
        <td align="center">$\colorbox{olive}{114}$</td>
        <td align="center">$\colorbox{olive}{584}$</td>
    </tr>
</table>

<p align="justify">
    O resultado da soma foi 4112. Vale-se destacar que o programa imprime, para o exemplo dado, dois resultados: o local e o global. O resultado local refere-se ao resultado da soma do caminho percorrido pela matriz, enquanto o global mostra a soma das somas das matrizes. Como o arquivo <i>input.data</i> possui apenas uma matriz, os resultados local e global possuem o mesmo valor. Segue abaixo as direções tomadas pelo algoritmo:
</p>

<table align="center">
    <tr>
        <td align="center">&#x21D3;</td>
        <td align="center"></td>
        <td align="center"></td>
        <td align="center"></td>
    </tr>
    <tr>
        <td align="center">&#x21D2;</td>
        <td align="center">&#x21D9;</td>
        <td align="center"></td>
        <td align="center"></td>
    </tr>
    <tr>
        <td align="center">&#x21D8;</td>
        <td align="center"></td>
        <td align="center"></td>
        <td align="center"></td>
    </tr>
    <tr>
        <td align="center"></td>
        <td align="center">&#x21D2;</td>
        <td align="center">&#x21D2;</td>
        <td align="center">&#x2717;</td>
    </tr>
</table>

<h2>Compilação e Execução</h2>

<p align="justify">
    O algoritmo do caminho guloso disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:
</p>


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


<h2>Contato</h2>

<a style="color:black" href="mailto:rafaelg000@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
    ✉️ <i>rafaelg000@gmail.com</i>
</a>

