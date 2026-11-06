# FPS Battle — PS2 Homebrew

Jogo original de tiro em primeira pessoa para PlayStation 2. Projeto independente, em C, com PS2SDK.

## Estado atual

**Fase 0 — fundação técnica.** O primeiro objetivo é compilar um ELF mínimo e confirmar a inicialização no console. Ainda não existe gameplay 3D nesta etapa.

## Alvo

- PlayStation 2, incluindo o modelo Slim SCPH-90010.
- Executável ELF para teste pelo uLaunchELF/OPL.
- Desenvolvimento em C com PS2SDK; gráficos 3D serão adicionados depois com gsKit.
- Compilação remota pelo GitHub Actions para não exigir PC local.

## Roadmap

1. **Alpha 0.1 — Base:** inicialização, loop principal e leitura do controle.
2. **Alpha 0.2 — FPS:** câmera em primeira pessoa, movimentação e colisão.
3. **Alpha 0.3 — Combate:** arma, tiro, munição, vida e HUD.
4. **Alpha 0.4 — Bots:** inimigos simples e arena de treinamento.
5. **Alpha 0.5 — Conteúdo:** mapas, armas, menus, personagens e emotes.
6. **Futuro:** modos offline maiores e pesquisa de multiplayer real. Online depende de rede, servidor e testes; não será apresentado como funcional antes disso.

## Controles planejados

- Analógico esquerdo: movimentação.
- Analógico direito: câmera.
- X: disparar.
- Quadrado: recarregar.
- START: pausar.

Os controles podem mudar após testes no hardware.

## Compilar

O workflow **Build PS2 ELF** compila o projeto em um ambiente PS2DEV e publica o arquivo fps-battle.elf como artefato quando a compilação termina.

Também é possível compilar localmente com PS2SDK instalado:

    make

## Testar no PS2

Baixe o artefato ELF na execução concluída do GitHub Actions. Transfira para o console e execute pelo uLaunchELF. OPL pode ser usado conforme o método de carregamento disponível.

## Referências

- PS2DEV: https://ps2dev.github.io/
- PS2SDK: https://github.com/ps2dev/ps2sdk
- gsKit: https://github.com/ps2dev/gsKit

## Segurança e escopo

O workflow usa uma imagem pública de desenvolvimento PS2 e actions oficiais do GitHub. Não são necessários tokens ou segredos personalizados para compilar.