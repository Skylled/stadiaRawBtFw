// 600eab3a  FUN_600eab3a  size=30 bytes
// --- callers ---
//   600eab58 FUN_600eab58
//   600eaba4 FUN_600eaba4
//   600eb1d4 FUN_600eb1d4
// --- callees ---
//   600e1e54 FUN_600e1e54


uint FUN_600eab3a(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  for (iVar2 = 0; iVar2 < *(int *)(param_1 + 0x28); iVar2 = iVar2 + 1) {
    uVar1 = uVar1 | *(uint *)(param_2 + iVar2 * 4);
  }
  uVar1 = FUN_600e1e54(uVar1);
  return ~uVar1;
}


