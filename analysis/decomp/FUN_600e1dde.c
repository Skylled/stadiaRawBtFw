// 600e1dde  FUN_600e1dde  size=118 bytes
// --- callers ---
//   60085c98 p_x25519_asn1__60085c98
// --- callees ---
//   600e0e02 FUN_600e0e02
//   600e1a12 FUN_600e1a12
//   60087964 FUN_60087964
//   600e17cc FUN_600e17cc
//   600e1830 FUN_600e1830
//   600875a0 FUN_600875a0


void FUN_600e1dde(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  byte local_148 [4];
  undefined4 auStack_144 [6];
  byte local_129;
  undefined1 auStack_128 [40];
  undefined1 auStack_100 [40];
  undefined1 auStack_d8 [40];
  undefined1 auStack_b0 [40];
  undefined1 auStack_88 [40];
  undefined1 auStack_60 [80];
  
  pbVar4 = local_148;
  puVar2 = param_2;
  do {
    puVar3 = puVar2 + 2;
    uVar1 = puVar2[1];
    *(undefined4 *)pbVar4 = *puVar2;
    *(undefined4 *)((int)pbVar4 + 4) = uVar1;
    pbVar4 = (byte *)((int)pbVar4 + 8);
    puVar2 = puVar3;
  } while (puVar3 != param_2 + 8);
  local_148[0] = local_148[0] & 0xf8;
  local_129 = local_129 & 0x7f | 0x40;
  FUN_60087964(auStack_b0,local_148);
  FUN_600e17cc(auStack_128,auStack_60,auStack_88);
  FUN_600e1830(auStack_100,auStack_60,auStack_88);
  FUN_600e1a12(auStack_d8,auStack_100);
  FUN_600e0e02(auStack_d8,auStack_128);
  FUN_600875a0(param_1,auStack_d8);
  return;
}


