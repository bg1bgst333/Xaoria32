// 二重インクルード防止
#ifndef __ENEMY_MAP_DATA_H__
#define __ENEMY_MAP_DATA_H__

// エネミーマップデータ構造体EnemyMapData
struct EnemyMapData{
	int m_x;	// x座標.
	int m_y;	// y座標.
	int m_nEnemyNo;	// エネミー番号.
	int m_nLife;	// ライフ.
	int m_nState;	// 状態.
	int m_nScore;	// 獲得スコア.
	int m_nExplosionAnimation;	// 爆発アニメ.
};

#endif
