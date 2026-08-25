// 600f55a4  FUN_600f55a4  size=346 bytes
// --- callers ---
//   600f5446 FUN_600f5446
//   600f52ee FUN_600f52ee
//   600f539c FUN_600f539c
//   600f57f6 FUN_600f57f6
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ad494 FUN_600ad494
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 * FUN_600f55a4(int *param_1,short *param_2,undefined2 param_3)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort local_e;
  int *local_c;
  
  local_e = 0x20;
  if (param_2 == (short *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    if (*param_2 == 2) {
      local_e = 0x10;
    }
    else if (*param_2 == 4) {
      local_e = 0x14;
    }
    if (*(ushort *)((int)param_1 + 0x1a) < *(ushort *)(param_1 + 6)) {
      if (((uint)param_1[5] < (uint)local_e) && (iVar2 = FUN_600ad494(param_1), iVar2 == 0)) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        thunk_EXT_FUN_0000b5ba(param_1[1],0,local_e);
        puVar3 = (undefined4 *)param_1[1];
        if ((*param_2 == 2) && (param_2[2] != 0)) {
          *(undefined1 *)(puVar3 + 2) = 0;
          *(short *)((int)puVar3 + 0xe) = param_2[2];
        }
        else if (*param_2 == 4) {
          iVar2 = param_1[1];
          *(undefined1 *)(iVar2 + 8) = 2;
          *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_2 + 2);
        }
        else if (*param_2 == 0x10) {
          iVar2 = param_1[1];
          *(undefined1 *)(iVar2 + 8) = 1;
          thunk_EXT_FUN_0000b572(iVar2 + 0xe,param_2 + 2,0x10);
        }
        param_1[1] = param_1[1] + (uint)local_e;
        param_1[5] = param_1[5] - (uint)local_e;
        sVar1 = *(short *)((int)param_1 + 0x1a);
        *(short *)((int)param_1 + 0x1a) = sVar1 + 1;
        *(short *)(puVar3 + 3) = sVar1;
        *(undefined2 *)((int)puVar3 + 10) = param_3;
        *puVar3 = 0;
        if (*param_1 == 0) {
          *param_1 = (int)puVar3;
        }
        else {
          for (local_c = (int *)*param_1; (local_c != (int *)0x0 && (*local_c != 0));
              local_c = (int *)*local_c) {
          }
          *local_c = (int)puVar3;
        }
      }
    }
    else {
      puVar3 = (undefined4 *)0x0;
    }
  }
  return puVar3;
}


