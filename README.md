<h1 align="center"> Slot-Machine </h1>
<p align="center">
<img src="http://img.shields.io/static/v1?label=VERSAO&message=v0.0.0&color=blue&style=for-the-badge"/>
</p>
<p align="center">
<img src="http://img.shields.io/static/v1?label=code_quality&message=C-Plus-Plus&color=res&style=for-the-badge"/>
</p>
<p align="center">
<img src="http://img.shields.io/static/v1?label=STATUS&message=CONCLUIDO&color=GREEN&style=for-the-badge"/>
</p>


<div align="center">

![jackpot](https://github.com/ThiagoLahass/Slot-Machine/blob/main/images.jpg)

  </div>

## Índice 

* [Índice](#índice)
* [Resumo](#resumo)
* [Descrição do Projeto](#descrição-do-projeto)
* [Materiais Utilizados](#materiais-utilizados)
* [Esquemático](#esquemático)
* [Código Principal](#código-principal)
* [Status do Projeto](#status-do-projeto)
* [Funcionalidades e Demonstração da Aplicação](#funcionalidades-e-demonstração-da-aplicação)
* [Acesso ao Projeto](#acesso-ao-projeto)
* [Tecnologias utilizadas](#tecnologias-utilizadas)
* [Desenvolvedores](#desenvolvedores)

## Resumo
O projeto trata-se da implementação em arduino de uma Slot Machine. Também conhecida como máquina caca níquel,
consiste em um tipo de máquina de apostas originalmente americana, baseada em sorteios de ícones e premiações em modas de acordo
com as combinações dos ícones.


## Descrição do Projeto
Para a construção do projeto, cada uma das três roletas da máquina giram através de motores de passo controlados por um arduino Uno.
A máquina será composta de três sistemas que funcionam em conjunto para realizar um jogo. 
  O primeiro sistema envolve a criação de um mecanismo de apostas, onde haverão dois botões
que executam as funções de incrementar ou decrementar a aposta atual do jogo,
um botão para o início de uma jogada, além de um botão para parar de jogar.
Além disso há uma interface composta por um display que descreve o valor da aposta atual, os créditos do jogador,
quantos pontos ganhou ou perdeu, e todas as informações necessárias, onde cada aposta será subtraída
do valor dos créditos assim que o botão para iniciar a jogada for pressionado. 
No início de cada rodada, o jogador tem um total de 100 pontos e pode apostar 10, 20 ou 30 créditos em cada jogada. 
Após a realização do sorteio de uma combinação de ícones, caso esta for uma combinação de dois ou três ícones iguais
incrementa-se uma certa quantidade de pontos que depende do ícone sorteado e que é proporcional a quantidade de pontos
que foi apostada no jogo. Caso o jogador não possua pontos suficientes para apostar novamente a partida termina e então o jogo reinicia.

## Materiais Utilizados
- 1 Arduino Uno
- 3 Resistores de 330 Ohms
- 3 Botões
- 1 Display com interface I2c
- 3 Motores de passo com um controlador cada
- 6 Engrenagens de plástico
- Jumpers

## Esquemático
Esquemático do tipo Protoboard:
![Protoboard]()
O esquemático pode ser visualizado com detalhes clicando [aqui](https://github.com/ThiagoLahass/Slot-Machine/blob/a49005407387b00b09cc741ba08f336f8a22dda2/Esquem%C3%A1tico_Slot_Machine_Esquem%C3%A1tico_PDF.pdf).

## Código Principal
Para acessar o código principal você pode clicar [aqui](https://github.com/ThiagoLahass/Slot-Machine/blob/main/Slot%20Machine.ino).

## Status do Projeto
  :white_check_mark: Projeto concluído com sucesso, com algumas funcionalidades a mais do que o projeto inicial apresentado.

## Funcionalidades e Demonstração da Aplicação
### :hammer: Funcionalidades do projeto

✔️ `Funcionalidade 1` `Aumentar Aposta`:   O botão Amarelo permite ao jogador aumentar a aposta de 10 em 10 unidades, até o limite máximo por jogada, que é de 30 unidades.
 
✔️ `Funcionalidade 2` `Diminuir Aposta`:   O botão Vermelho permite ao jogador diminuir a aposta de 10 em 10 unidades, até o limite mínimo por jogada, que é de 10 unidades.
 
✔️ `Funcionalidade 3` `Jogar`:             O botão Verde permite ao jogador iniciar a jogada após ele escolher quantas unidades deseja apostar.

✔️ `Funcionalidade 4` `Parar de jogar`:    O botão restante permite ao jogador parar de jogar com a quantidade de unidades que possui.

## Acesso ao Projeto
### 📁 Acesso ao projeto
 Você pode acessar os arquivos do projeto clicando [aqui](https://github.com/ThiagoLahass/Slot-Machine.git).

### 🛠️ Abrir e rodar o projeto

Se for do interesse do leitor, para utilizar o projeto basta fazer o seu dowload [aqui](https://github.com/ThiagoLahass/Slot-Machine.git), abrir o código principal atraves da [Arduino IDE](https://www.arduino.cc/en/software) e fazer o seu upload para o Arduino através da Arduino IDE após fazer a montagem do hardware do projeto.

### :video_game: Jogar

Para jogar o jogador deve selecionar a sua aposta através da interface criada pelo display e botões, iniciar a jogada e dependendo da combinação
que o jogador consegue ele ganha ou perde pontos naquela rodada. O jogo acaba quando o jogador não possuí pontos suficientes para apostar novamente ou desiste de jogar apertando
o botão existente para essa escolha.

## Tecnologias utilizadas

- ``C++``

## Desenvolvedores

| [<img src="https://avatars.githubusercontent.com/u/91209141?s=400&u=a6853a4dc0b54f8347d0b85f4a0b56c725dc1b3a&v=4" width=115><br><sub>Thiago Lahass</sub>](https://github.com/ThiagoLahass) | <img src="https://user-images.githubusercontent.com/91209141/158442505-09560fe5-5c19-4fa0-9b4a-9a45edb1507a.jpg" width=115><br><sub>Luiz Bazoni</sub> | <img src="https://user-images.githubusercontent.com/91209141/158442548-22e4ecff-242a-4841-819c-e7ffa72a0543.jpg" width=115><br><sub>Daniel Ferrari</sub> |
| :---: | :---: | :---: |
