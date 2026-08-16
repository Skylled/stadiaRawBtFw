// 60058600  FUN_60058600  size=296 bytes
// --- callers ---
//   60058754 buffer__60058754
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   60101b76 FUN_60101b76
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60101b4c FUN_60101b4c
//   6013d258 thunk_EXT_FUN_0000b50a
//   600d3638 FUN_600d3638
//   600cbdf4 buffer__600cbdf4


void FUN_60058600(int param_1,code *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  undefined4 *local_c4;
  undefined4 *puStack_c0;
  undefined4 local_bc;
  undefined1 *local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa [134];
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x1824);
  if (*(int *)(param_1 + 0x80c) == *(int *)(param_1 + 0x810)) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x804) + *(int *)(param_1 + 0x810));
  }
  iVar2 = *(int *)(param_1 + 0x1820);
  bVar5 = *(int *)(param_1 + 0x181c) != iVar2;
  if (bVar5) {
    puVar3 = *(undefined4 **)(param_1 + 0x1814);
  }
  else {
    puVar3 = (undefined4 *)0x0;
  }
  bVar1 = false;
  if (bVar5) {
    puVar3 = (undefined4 *)((int)puVar3 + iVar2);
  }
  local_b8 = local_aa;
  local_ac = 0;
  local_ab = 0;
  local_aa[0] = 0;
  local_b4 = 0x80;
  uStack_b0 = 0;
LAB_6005866c:
  do {
    if (puVar4 == (undefined4 *)0x0) {
LAB_600586b2:
      if (puVar3 == (undefined4 *)0x0) {
        if (bVar1) {
          local_bc = 0x280000;
          local_c4 = puVar3;
          puStack_c0 = puVar3;
          FUN_60101b4c(&local_b8);
          FUN_60101b76(&local_b8,DAT_60058728);
          (*param_2)(param_3,&local_c4);
        }
        thunk_EXT_FUN_00007d10(param_1 + 0x1824);
        return;
      }
LAB_600586ea:
      iVar2 = FUN_600d3638(puVar3);
      if (iVar2 == 0) {
        bVar1 = true;
        puVar3 = (undefined4 *)0x0;
        goto LAB_6005866c;
      }
      local_c4 = (undefined4 *)puVar3[1];
      puStack_c0 = (undefined4 *)puVar3[2];
      local_bc = puVar3[3];
      FUN_60101b4c(&local_b8);
      thunk_EXT_FUN_0000b50a(&local_b8,puVar3 + 4,*puVar3);
      puVar3 = (undefined4 *)buffer__600cbdf4(param_1 + 0x1814,puVar3);
    }
    else {
      if ((puVar3 != (undefined4 *)0x0) && ((uint)puVar3[2] < (uint)puVar4[2])) goto LAB_600586ea;
      iVar2 = FUN_600d3638(puVar4);
      if (iVar2 == 0) {
        bVar1 = true;
        puVar4 = (undefined4 *)0x0;
        goto LAB_600586b2;
      }
      local_c4 = (undefined4 *)puVar4[1];
      puStack_c0 = (undefined4 *)puVar4[2];
      local_bc = puVar4[3];
      FUN_60101b4c(&local_b8);
      thunk_EXT_FUN_0000b50a(&local_b8,puVar4 + 4,*puVar4);
      puVar4 = (undefined4 *)buffer__600cbdf4(param_1 + 0x804,puVar4);
    }
    (*param_2)(param_3,&local_c4);
  } while( true );
}


