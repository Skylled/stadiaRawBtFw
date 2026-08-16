// 60069c58  adapter__60069c58  size=232 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   6009598c FUN_6009598c
//   600d8994 FUN_600d8994
//   60069c10 adapter__60069c10
//   60101b76 FUN_60101b76
//   6010165c FUN_6010165c
//   600d37ac FUN_600d37ac
//   600d3b3a FUN_600d3b3a
//   600cbb14 FUN_600cbb14
//   601016f0 FUN_601016f0
//   600d88f4 FUN_600d88f4
//   600d8970 FUN_600d8970
//   600d8946 FUN_600d8946


/* src: adapter.cc */

void adapter__60069c58(int param_1,undefined2 param_2,undefined4 *param_3)

{
  short sVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  short *psVar8;
  undefined4 *puVar9;
  undefined1 local_b4 [4];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [144];
  undefined4 *puVar10;
  
  iVar2 = FUN_600d8994(param_1 + 0x110);
  if (iVar2 == 0) {
    FUN_6010165c(0x28,DAT_60069d44,0x3a4,DAT_60069d48,DAT_60069d40);
  }
  else {
    psVar8 = *(short **)(param_1 + 0x1ab4);
    do {
      if (*(short **)(param_1 + 0x1ab4) + *(int *)(param_1 + 0x1ab8) * 0xcca == psVar8)
      goto LAB_60069cc4;
      sVar1 = *psVar8;
      psVar8 = psVar8 + 0xcca;
    } while (sVar1 == -1);
    FUN_600d8970(param_1 + 0x1ab4,*(undefined2 *)(param_1 + 0x120));
    FUN_600d88f4(param_1);
LAB_60069cc4:
    puVar3 = (undefined2 *)FUN_600d8946(param_1 + 0x1ab4,0xffffffff);
    if (puVar3 == (undefined2 *)0x0) {
      local_b0 = DAT_60069d44;
      local_ac = 0x3b2;
      FUN_600d3b3a(auStack_a8);
      FUN_600d37ac(auStack_a8,DAT_60069d4c);
      local_b4[0] = 8;
      uVar7 = FUN_600cbb14(local_b4);
      FUN_60101b76(auStack_a8,uVar7);
      FUN_601016f0(0x1e,local_b0,local_ac,auStack_a8);
      FUN_6009598c(param_2);
    }
    else {
      *puVar3 = param_2;
      puVar4 = (undefined4 *)(puVar3 + 2);
      puVar9 = param_3;
      do {
        puVar10 = puVar9 + 1;
        puVar5 = puVar4 + 1;
        *puVar4 = *puVar9;
        puVar4 = puVar5;
        puVar9 = puVar10;
      } while (puVar10 != param_3 + 5);
      *(undefined1 *)puVar5 = *(undefined1 *)puVar10;
      *(undefined2 *)(param_1 + 0x1ab2) = param_2;
      piVar6 = (int *)adapter__60069c10(param_1);
      (**(code **)(*piVar6 + 0x18))(piVar6,param_3);
    }
  }
  return;
}


