// 600ea77a  FUN_600ea77a  size=42 bytes
// --- callers ---
//   60084d34 ecdsa_asn1__60084d34
// --- callees ---
//   600ea75c FUN_600ea75c
//   600e092c FUN_600e092c
//   6008b384 bcm__6008b384


int * FUN_600ea77a(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)FUN_600e092c(8);
  piVar3 = piVar1;
  if (piVar1 != (int *)0x0) {
    iVar2 = bcm__6008b384();
    *piVar1 = iVar2;
    iVar2 = bcm__6008b384();
    piVar1[1] = iVar2;
    if ((*piVar1 == 0) || (iVar2 == 0)) {
      piVar3 = (int *)0x0;
      FUN_600ea75c(piVar1);
    }
  }
  return piVar3;
}


