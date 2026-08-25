// 600f484a  FUN_600f484a  size=214 bytes
// --- callers ---
//   600acf50 FUN_600acf50
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ac524 FUN_600ac524
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600f484a(undefined4 param_1,int param_2,ushort param_3,byte *param_4)

{
  short sVar1;
  ushort local_32;
  undefined1 auStack_28 [20];
  short local_14;
  short local_12;
  byte *local_c;
  
  if ((*(char *)(param_2 + 0x31) == '\x01') && (*(char *)(param_2 + 0x32) == '\x02')) {
    local_c = param_4;
    thunk_EXT_FUN_0000b5ba(auStack_28,0,0x1c);
    local_32 = param_3;
    while (3 < local_32) {
      local_14 = (ushort)local_c[1] * 0x100 + (ushort)*local_c;
      local_12 = (ushort)local_c[3] * 0x100 + (ushort)local_c[2];
      local_c = local_c + 4;
      thunk_EXT_FUN_0000b572(auStack_28,param_2 + 0x10,0x14);
      local_32 = local_32 - 4;
      if (*(int *)(*(int *)(param_2 + 4) + 0x1c) != 0) {
        (**(code **)(*(int *)(param_2 + 4) + 0x1c))
                  (*(undefined2 *)(param_2 + 0x24),*(undefined1 *)(param_2 + 0x32),auStack_28);
      }
    }
    if (local_12 == 0) {
      sVar1 = 0;
    }
    else {
      sVar1 = local_12 + 1;
    }
    *(short *)(param_2 + 0x28) = sVar1;
    FUN_600ac524(param_2);
  }
  return;
}


