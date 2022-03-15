<h1 align="center"> Slot-Machine </h1>
<p align="center">
<img src="http://img.shields.io/static/v1?label=VERSAO&message=v0.0.0&color=blue&style=for-the-badge"/>
</p>
<p align="center">
<img src="http://img.shields.io/static/v1?label=code_quality&message=C-Sharp&color=GREEN&style=for-the-badge"/>
</p>

<div align="center">

![jackpot](https://github.com/ThiagoLahass/Slot-Machine/blob/main/images.jpg)

  </div>

## Índice 

* [Índice](#índice)
* [Resumo](#resumo)
* [Descrição do Projeto](#descrição-do-projeto)
* [Status do Projeto](#status-do-projeto)
* [Funcionalidades e Demonstração da Aplicação](#funcionalidades-e-demonstração-da-aplicação)
* [Acesso ao Projeto](#acesso-ao-projeto)
* [Tecnologias utilizadas](#tecnologias-utilizadas)
* [Pessoas Desenvolvedoras do Projeto](#pessoas-desenvolvedoras-do-projeto)
* [Conclusão](#conclusão)
* [Copyright](#copyright)

## Resumo
O objetivo é produzir uma máquina caça-níqueis utilizando um microcontrolador Arduino. A
máquina será composta de três sistemas que funcionam em conjunto para realizar um jogo. O
primeiro sistema envolve a criação de um mecanismo de apostas, onde haverão dois botões
para o controle de apostas, um botão para o início de uma jogada, além de um botão para parar de jogar.
Além disso há um display que descreve o valor da aposta atual, os créditos do jogador, quantos pontos ganhou ou perdeu,
e as todas as informações necessárias, onde cada aposta será subtraída
do valor dos créditos assim que o botão para iniciar a jogada for pressionado. O segundo
sistema irá sortear três ícones dentro de um espaço amostral e uma eventual premiação em
créditos para o jogador caso os ícones sorteados correspondam a ao menos um de uma série
de combinações já definidas. O terceiro sistema tem o objetivo de representar o sorteio por
meio de três roletas controladas por motores, onde estarão impressos de forma radial todos os
possíveis ícones para sorteio, que devem ser alinhados em direção ao painel conforme o
resultado gerado. O jogo termina e o sistema reinicia caso após uma jogada o valor total dos
créditos do jogador for menor do que a aposta miníma.

## Descrição do Projeto

## Status do Projeto
  Projeto concluído com sucesso, com algumas funcionalidades a mais do que o projeto inicial apresentado.

## Funcionalidades e Demonstração da Aplicação
### :hammer: Funcionalidades do projeto

- `Funcionalidade 1` `Aumentar Aposta`:   O botão Amarelo permite ao jogador aumentar a aposta de 10 em 10 unidades, até o limite máximo por jogada, que é de 30 unidades.
 
- `Funcionalidade 2` `Diminuir Aposta`:   O botão Vermelho permite ao jogador diminuir a aposta de 10 em 10 unidades, até o limite mínimo por jogada, que é de 10 unidades.
 
- `Funcionalidade 3` `Jogar`:             O botão Verde permite ao jogador iniciar a jogada após ele escolher quantas unidades deseja apostar.

- `Funcionalidade 4` `Parar de jogar`:    O botão restante permite ao jogador parar de jogar com a quantidade de unidades que possui.

## Acesso ao Projeto
### 📁 Acesso ao projeto
 Você pode acessar os arquivos do projeto clicando [aqui](https://github.com/ThiagoLahass/Slot-Machine.git), e o código principal se encontra disponivel em [Slot machine.ino](https://github.com/ThiagoLahass/Slot-Machine/blob/main/Slot%20Machine.ino).

### 🛠️ Abrir e rodar o projeto

Para utilizar o projeto basta fazer o seu dowload [aqui](https://github.com/ThiagoLahass/Slot-Machine.git), abrir o código principal atraves da [Arduino IDE](https://www.arduino.cc/en/software) e fazer o seu upload para o Arduino através da Arduino IDE após fazer a montagem do hardware do projeto.

## Tecnologias utilizadas

- ``C#``

## Pessoas Desenvolvedoras do Projeto

| [<img src="https://avatars.githubusercontent.com/u/91209141?s=400&u=a6853a4dc0b54f8347d0b85f4a0b56c725dc1b3a&v=4" width=115><br><sub>Thiago Lahass</sub>](https://github.com/ThiagoLahass) | <img src="https://user-images.githubusercontent.com/91209141/158442505-09560fe5-5c19-4fa0-9b4a-9a45edb1507a.jpg" width=115><br><sub>Luiz Bazoni</sub> | <img src="https://user-images.githubusercontent.com/91209141/158442548-22e4ecff-242a-4841-819c-e7ffa72a0543.jpg" width=115><br><sub>Daniel Ferrari</sub> |
| :---: | :---: | :---: |

## Conclusão

## Copyright
Copyright ©️ 2022 - Slot Machine
