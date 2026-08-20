// 600e1cd4  FUN_600e1cd4  size=158 bytes
// --- callers ---
//   60087964 FUN_60087964
// --- callees ---
//   600e0e02 FUN_600e0e02
//   600e1730 FUN_600e1730
//   600e17cc FUN_600e17cc
//   600e1830 FUN_600e1830


void FUN_600e1cd4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_b8 [40];
  undefined1 auStack_90 [40];
  undefined1 auStack_68 [40];
  undefined1 auStack_40 [40];
  
  iVar1 = FUN_600e17cc(param_1,param_2 + 0x28,param_2);
  iVar1 = iVar1 + 0x28;
  FUN_600e1830(iVar1,param_2 + 0x28,param_2);
  FUN_600e0e02(auStack_68,param_1,param_3);
  FUN_600e0e02(auStack_90,iVar1,param_3 + 0x28);
  FUN_600e0e02(auStack_40,param_3 + 0x78,param_2 + 0x78);
  FUN_600e0e02(auStack_b8,param_2 + 0x50,param_3 + 0x50);
  iVar2 = param_1 + 0x78;
  FUN_600e17cc(iVar2,auStack_b8);
  FUN_600e1830(param_1,auStack_68,auStack_90);
  FUN_600e17cc(iVar1,auStack_68,auStack_90);
  FUN_600e1730(auStack_68,iVar2);
  FUN_600e17cc(param_1 + 0x50,auStack_68,auStack_40);
  FUN_600e1830(iVar2,auStack_68,auStack_40);
  return;
}


