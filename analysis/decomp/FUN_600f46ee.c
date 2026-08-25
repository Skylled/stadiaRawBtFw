// 600f46ee  FUN_600f46ee  size=178 bytes
// --- callers ---
//   600f4b8e FUN_600f4b8e
// --- callees ---
//   600f46b4 FUN_600f46b4
//   6013d168 thunk_EXT_FUN_0000b554


bool FUN_600f46ee(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 local_a;
  
  iVar3 = *(int *)(param_2 + 0xc);
  bVar1 = false;
  local_a = 1;
  if (param_3 != 0) {
    if (((*(short *)(param_3 + 2) == *(short *)(iVar3 + 2)) &&
        (*(short *)(param_3 + 6) == *(short *)(param_2 + 0x2c))) &&
       (iVar2 = thunk_EXT_FUN_0000b554
                          (param_3 + 9,iVar3 + 9 + (uint)*(ushort *)(iVar3 + 4),
                           *(undefined2 *)(param_3 + 6)), iVar2 == 0)) {
      *(undefined1 *)(param_2 + 0x33) = 0;
      *(short *)(iVar3 + 4) = *(short *)(param_3 + 6) + *(short *)(iVar3 + 4);
      if (*(ushort *)(iVar3 + 6) <= *(ushort *)(iVar3 + 4)) {
        bVar1 = true;
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x33) = 0x85;
      local_a = 0;
      bVar1 = true;
    }
  }
  if (bVar1) {
    FUN_600f46b4(param_1,param_2,local_a);
  }
  return bVar1;
}


