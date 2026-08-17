// 60068278  battery_charger_bq25601__60068278  size=106 bytes
// src: battery_charger_bq25601.h
// --- callers ---
//   600686e4 FUN_600686e4
// --- callees ---
//   600d835e FUN_600d835e
//   6010165c FUN_6010165c
//   600d8322 FUN_600d8322


/* src: battery_charger_bq25601.h */

char battery_charger_bq25601__60068278
               (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = DAT_600682e4;
  cVar2 = FUN_600d8322(param_1,*DAT_600682e4,param_3,param_4,param_1,param_2,param_3,param_4);
  if (cVar2 == '\0') {
    **(byte **)piVar1[1] =
         **(byte **)piVar1[1] & 0xf |
         (byte)((int)(param_2 - (uint)*(ushort *)(piVar1 + 2)) /
                (int)(uint)*(ushort *)((int)piVar1 + 10) << 4);
    FUN_6010165c(0x14,DAT_600682e8,0x81,DAT_600682f0,DAT_600682ec,
                 (int)*(short *)((int)piVar1 + 10) * ((int)(uint)**(byte **)piVar1[1] >> 4) +
                 (uint)*(ushort *)(piVar1 + 2) & 0xffff,param_2,**(undefined1 **)(*piVar1 + 4));
    cVar2 = FUN_600d835e(param_1,*piVar1);
  }
  return cVar2;
}


