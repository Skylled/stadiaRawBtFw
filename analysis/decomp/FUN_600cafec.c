// 600cafec  FUN_600cafec  size=64 bytes
// --- callers ---
//   600cb030 mpu__600cb030
// --- callees ---
//   60100ad0 FUN_60100ad0


undefined4 FUN_600cafec(uint param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 < 0x10) && (iVar3 = FUN_60100ad0(param_2,param_3), iVar1 = DAT_600cb02c, iVar3 != 0))
  {
    uVar2 = 0;
    *(uint *)(DAT_600cb02c + 8) = param_1;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffe;
    *(undefined4 *)(iVar1 + 0xc) = param_2;
    *(uint *)(iVar1 + 0x10) = param_3 | 1;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}


