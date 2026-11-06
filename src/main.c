#include <tamtypes.h>
#include <kernel.h>
#include <debug.h>

/*
 * FPS Battle - primeiro teste de inicializacao.
 * Esta versao confirma que o ELF inicia e mantem o EE ativo.
 * Video 3D, leitura do DualShock 2 e gameplay serao adicionados
 * em etapas separadas, com testes no hardware real.
 */
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    init_scr();
    scr_printf("\n");
    scr_printf("FPS BATTLE - PS2 HOMEBREW\n");
    scr_printf("-------------------------\n");
    scr_printf("Alpha 0.1 - Base tecnica\n\n");
    scr_printf("ELF iniciado com sucesso.\n");
    scr_printf("Proxima etapa: video e controle.\n");

    while (1) {
        /* Loop principal temporario. */
        SleepThread();
    }

    return 0;
}
