// 60085728  p_ed25519_asn1__60085728  size=82 bytes
// src: p_ed25519_asn1.c
// --- callers ---
//   60085780 p_ed25519_asn1__60085780
// --- callees ---
//   600e092c FUN_600e092c
//   600e0552 FUN_600e0552
//   600e0890 FUN_600e0890
//   600e1d72 FUN_600e1d72


/* src: p_ed25519_asn1.c */

undefined4 p_ed25519_asn1__60085728(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_30 [32];
  
  if (param_3 == 0x20) {
    iVar1 = FUN_600e092c(0x41);
    if (iVar1 != 0) {
      FUN_600e1d72(auStack_30,iVar1,param_2);
      *(undefined1 *)(iVar1 + 0x40) = 1;
      FUN_600e0890(param_1);
      *(int *)(param_1 + 8) = iVar1;
      return 1;
    }
    uVar2 = 0x41;
    uVar3 = 0x27;
  }
  else {
    uVar2 = 0x66;
    uVar3 = 0x21;
  }
  FUN_600e0552(6,0,uVar2,DAT_6008577c,uVar3);
  return 0;
}


