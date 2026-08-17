// 6006e484  gki_ft__6006e484  size=200 bytes
// src: gki_ft.c
// --- callers ---
//   6006e56c FUN_6006e56c
//   6006ecfc FUN_6006ecfc
//   6006bf74 FUN_6006bf74
// --- callees ---
//   6013d028 thunk_EXT_FUN_00006a20
//   60100900 FUN_60100900
//   601016a2 FUN_601016a2
//   6013d000 thunk_EXT_FUN_00007dac
//   6006be9c FUN_6006be9c
//   601007e6 FUN_601007e6
//   6013d360 thunk_EXT_FUN_00007d64


/* src: gki_ft.c */

undefined4
gki_ft__6006e484(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                ushort param_5)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar1 = DAT_6006e558;
  if (param_2 < 8) {
    FUN_6006be9c(DAT_6006e550,DAT_6006e554,param_1,param_2,param_3,param_4,param_5);
    iVar2 = FUN_601007e6(1);
    *(int *)(iVar1 + param_2 * 4 + 0x24) = iVar2;
    puVar3 = PTR_s_GKI_create_task_create_thread_ev_6006e55c;
    if (iVar2 != 0) {
      iVar2 = thunk_EXT_FUN_00006a20(100,2,0);
      *(int *)(iVar1 + param_2 * 4 + 0x44) = iVar2;
      puVar3 = PTR_s_GKI_create_task_create_thread_ev_6006e560;
      if (iVar2 != 0) {
        thunk_EXT_FUN_00007d64();
        iVar2 = FUN_60100900(param_1,param_3,param_5 >> 2,0,0x14 - param_2 & 0xff,
                             iVar1 + (param_2 + 1) * 4);
        if (iVar2 != 1) {
          FUN_601016a2(PTR_s_gki_ft_c_6006e568,0x94,PTR_s_FreeRTOS_CHECK_failed_6006e564);
        }
        *(undefined1 *)(iVar1 + param_2 + 0xec) = 1;
        *(char *)(iVar1 + param_2 + 0xc4) = (char)(0x14 - param_2);
        *(undefined4 *)(iVar1 + param_2 * 4 + 0xcc) = param_3;
        *(undefined4 *)(iVar1 + (param_2 + 0x4a) * 4 + 8) = 0;
        *(undefined2 *)(iVar1 + (param_2 + 0x78) * 2 + 4) = 0;
        thunk_EXT_FUN_00007dac();
        return 0;
      }
    }
  }
  else {
    param_3 = 8;
    puVar3 = DAT_6006e54c;
  }
  FUN_6006be9c(DAT_6006e550,puVar3,param_3);
  return 1;
}


