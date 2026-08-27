// 6005f164  FUN_6005f164  size=34 bytes
// --- callers ---
//   6006044c reset__6006044c
// --- callees ---
//   6005f110 FUN_6005f110


void FUN_6005f164(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) goto LAB_6005f17a;
  if (param_1 == 2) {
    uVar1 = 3;
  }
  else {
    if (param_1 != 0) goto LAB_6005f176;
    uVar1 = 1;
  }
  do {
    *(undefined4 *)(DAT_6005f188 + 0x34) = uVar1;
LAB_6005f176:
    FUN_6005f110();
LAB_6005f17a:
    uVar1 = 2;
  } while( true );
}


