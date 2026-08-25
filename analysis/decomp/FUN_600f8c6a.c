// 600f8c6a  FUN_600f8c6a  size=202 bytes
// --- callers ---
//   600f7d88 FUN_600f7d88
//   600ba1c4 FUN_600ba1c4
//   600bb760 FUN_600bb760
// --- callees ---
//   600bb7e4 FUN_600bb7e4
//   600b9408 FUN_600b9408


void FUN_600f8c6a(undefined4 param_1,short param_2,undefined1 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  int iVar1;
  undefined1 *local_10;
  ushort local_a;
  
  if (param_2 == 1) {
    local_a = 2;
  }
  else if (param_2 == 2) {
    local_a = 4;
  }
  else {
    local_a = 0;
  }
  iVar1 = FUN_600bb7e4(param_1,local_a + 2,1,param_3);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)param_2;
    local_10 = (undefined1 *)(iVar1 + 0x16);
    *(char *)(iVar1 + 0x15) = (char)((ushort)param_2 >> 8);
    if (1 < local_a) {
      *local_10 = (char)param_4;
      local_10 = (undefined1 *)(iVar1 + 0x18);
      *(char *)(iVar1 + 0x17) = (char)((ushort)param_4 >> 8);
    }
    if (3 < local_a) {
      *local_10 = (char)param_5;
      local_10[1] = (char)((ushort)param_5 >> 8);
    }
    FUN_600b9408(param_1,0,iVar1);
  }
  return;
}


