#include <tamtypes.h>
#include <kernel.h>
#include <debug.h>
#include <sifrpc.h>
#include <libpad.h>

static u8 pad_buffer[256] __attribute__((aligned(64)));

int main(int argc, char *argv[])
{
    struct padButtonStatus pad;
    u16 previous_buttons = 0xffff;
    int pad_open;

    (void)argc;
    (void)argv;
    init_scr();
    scr_printf("\nFPS BATTLE - PS2 HOMEBREW\n");
    scr_printf("-------------------------\n");
    scr_printf("Alpha 0.2 - Teste do controle\n\n");

    sceSifInitRpc(0);
    if (padInit(0) != 1) {
        scr_printf("ERRO: nao foi possivel iniciar libpad.\n");
        while (1) DelayThread(1000000);
    }

    pad_open = padPortOpen(0, 0, pad_buffer);
    if (!pad_open) {
        scr_printf("ERRO: nao foi possivel abrir a porta 1.\n");
        while (1) DelayThread(1000000);
    }

    scr_printf("Conecte o DualShock 2 na porta 1.\n");
    scr_printf("Aguardando controle ficar pronto...\n");

    while (1) {
        if (padGetState(0, 0) == PAD_STATE_STABLE && padRead(0, 0, &pad)) {
            u16 pressed = (u16)(~pad.btns);
            if (pressed != previous_buttons) {
                scr_printf("\nBotoes: ");
                if (pressed & PAD_START)    scr_printf("START ");
                if (pressed & PAD_SELECT)   scr_printf("SELECT ");
                if (pressed & PAD_UP)       scr_printf("CIMA ");
                if (pressed & PAD_DOWN)     scr_printf("BAIXO ");
                if (pressed & PAD_LEFT)     scr_printf("ESQUERDA ");
                if (pressed & PAD_RIGHT)    scr_printf("DIREITA ");
                if (pressed & PAD_CROSS)    scr_printf("X ");
                if (pressed & PAD_CIRCLE)   scr_printf("BOLA ");
                if (pressed & PAD_SQUARE)   scr_printf("QUADRADO ");
                if (pressed & PAD_TRIANGLE) scr_printf("TRIANGULO ");
                if (pressed & PAD_L1)       scr_printf("L1 ");
                if (pressed & PAD_R1)       scr_printf("R1 ");
                if (pressed & PAD_L2)       scr_printf("L2 ");
                if (pressed & PAD_R2)       scr_printf("R2 ");
                if (pressed == 0)           scr_printf("nenhum");
                previous_buttons = pressed;
            }
        }
        DelayThread(16666);
    }
    return 0;
}