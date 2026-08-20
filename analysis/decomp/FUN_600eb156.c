// 600eb156  FUN_600eb156  size=60 bytes
// --- callers ---
//   600eb7ce FUN_600eb7ce
// --- callees ---
//   600eafb4 FUN_600eafb4
//   600ea8d8 FUN_600ea8d8
//   600eaba4 FUN_600eaba4


void FUN_600eb156(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_dc [204];
  
  FUN_600eafb4(param_2,param_3);
  FUN_600ea8d8(param_1,auStack_dc,param_3);
  iVar1 = param_2 + 0xcc;
  do {
    iVar2 = iVar1 + 0xcc;
    FUN_600eaba4(param_1,iVar1,iVar1 + -0xcc,auStack_dc);
    iVar1 = iVar2;
  } while (iVar2 != param_2 + 0x660);
  return;
}


