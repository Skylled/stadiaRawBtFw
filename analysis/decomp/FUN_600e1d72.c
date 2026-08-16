// 600e1d72  FUN_600e1d72  size=108 bytes
// --- callers ---
//   60085728 p_ed25519_asn1__60085728
// --- callees ---
//   600e1c48 FUN_600e1c48
//   60087964 FUN_60087964
//   600ec31c FUN_600ec31c


void FUN_600e1d72(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte local_f0 [31];
  byte local_d1;
  undefined1 auStack_b0 [160];
  
  FUN_600ec31c(param_3,0x20,local_f0);
  local_f0[0] = local_f0[0] & 0xf8;
  local_d1 = local_d1 & 0x7f | 0x40;
  FUN_60087964(auStack_b0,local_f0);
  FUN_600e1c48(param_1,auStack_b0);
  puVar1 = param_3;
  puVar3 = param_2;
  do {
    puVar2 = puVar1 + 1;
    *puVar3 = *puVar1;
    puVar1 = puVar2;
    puVar3 = puVar3 + 1;
  } while (puVar2 != param_3 + 8);
  puVar1 = param_1;
  puVar3 = param_2 + 8;
  do {
    puVar2 = puVar1 + 1;
    *puVar3 = *puVar1;
    puVar1 = puVar2;
    puVar3 = puVar3 + 1;
  } while (puVar2 != param_1 + 8);
  return;
}


