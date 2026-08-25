// 600f47a0  FUN_600f47a0  size=170 bytes
// --- callers ---
//   600f4b8e FUN_600f4b8e
//   600f45a6 FUN_600f45a6
// --- callees ---
//   600b00b4 FUN_600b00b4
//   600f70b4 FUN_600f70b4


void FUN_600f47a0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined2 local_c;
  undefined2 local_a;
  
  iVar2 = *(int *)(param_2 + 0xc);
  local_a = *(short *)(iVar2 + 6) - *(short *)(iVar2 + 4);
  if ((int)(*(ushort *)(param_1 + 0x1a) - 5) < (int)(uint)local_a) {
    local_a = *(short *)(param_1 + 0x1a) - 5;
  }
  *(undefined2 *)(param_2 + 0x28) = *(undefined2 *)(iVar2 + 2);
  local_c = *(short *)(iVar2 + 4);
  if (*(char *)(param_2 + 0x32) == '\x03') {
    local_c = local_c + *(short *)(param_2 + 0x2e);
  }
  cVar1 = FUN_600f70b4(param_1,*(undefined2 *)(param_2 + 0x26),0x16,*(undefined2 *)(iVar2 + 2),
                       local_a,local_c,iVar2 + 9 + (uint)*(ushort *)(iVar2 + 4));
  *(ushort *)(param_2 + 0x2c) = local_a;
  if ((cVar1 != '\0') && (cVar1 != -0x7a)) {
    FUN_600b00b4(param_2,cVar1,0);
  }
  return;
}


