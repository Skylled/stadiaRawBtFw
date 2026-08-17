// 60084c90  bio__60084c90  size=46 bytes
// src: bio.c
// --- callers ---
//   600e028e FUN_600e028e
//   60067a68 gotham__60067a68
// --- callees ---
//   600e0552 FUN_600e0552


/* src: bio.c */

undefined4 bio__60084c90(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    if ((*param_1 != 0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x18), UNRECOVERED_JUMPTABLE != (code *)0x0))
    {
                    /* WARNING: Could not recover jumptable at 0x60084cbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
    FUN_600e0552(0x11,0,0x73,DAT_60084cc0,0xd0,param_2);
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


