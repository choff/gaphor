/*
 * Generalization
 *
 * This is LGPL'ed code.
 */

#include "generalization.h"
#include "common.h"
#include <diacanvas/dia-shape.h>
#include <diacanvas/dia-canvas-i18n.h>

static void generalization_class_init (RelationshipClass *klass);
static void generalization_init (Generalization *item);
static void generalization_dispose (GObject *object);
static void generalization_set_property (GObject *object,
					     guint property_id,
					     const GValue *value,
					     GParamSpec *pspec);
static void generalization_get_property (GObject *object,
					     guint property_id,
					     GValue *value,
					     GParamSpec *pspec);
static void generalization_update (DiaCanvasItem *item, gdouble affine[6]);
static gboolean generalization_connect (DiaCanvasItem *item, DiaHandle *handle);
static gboolean generalization_disconnect (DiaCanvasItem *item,
					   DiaHandle *handle);

static RelationshipClass *parent_class = NULL;

GType
generalization_get_type (void)
{
	static GType object_type = 0;

	if (!object_type) {
		static const GTypeInfo object_info = {
			sizeof (GeneralizationClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) generalization_class_init,
			(GClassFinalizeFunc) NULL,
			(gconstpointer) NULL, /* class_data */
			sizeof (Generalization),
			(guint16) 0, /* n_preallocs */
			(GInstanceInitFunc) generalization_init,
		};

		object_type = g_type_register_static (TYPE_RELATIONSHIP,
						      "Generalization",
						      &object_info, 0);
	}

	return object_type;
}


static void
generalization_class_init (RelationshipClass *klass)
{
	GObjectClass *object_class;
	DiaCanvasItemClass *item_class;
	
	object_class = (GObjectClass*) klass;
	item_class = DIA_CANVAS_ITEM_CLASS (klass);
	
	parent_class = g_type_class_peek_parent (klass);

	object_class->dispose = generalization_dispose;
	object_class->get_property = generalization_get_property;
	object_class->set_property = generalization_set_property;
	
	item_class->update = generalization_update;

	klass->subject_class = "Generalization";
	klass->head_name = "parent";
	klass->tail_name = "child";
	klass->head_xname = "specialization";
	klass->tail_xname = "generalization";
}


static void
generalization_init (Generalization *item)
{
	DiaCanvasLine *line = (DiaCanvasLine*) item;

	line->has_head = TRUE;
	line->head_a = 15.0;
	line->head_b = 15.0;
	line->head_c = 10.0;
	line->head_d = 10.0;
	line->head_fill_color = 0;
}


static void
generalization_set_property (GObject *object, guint property_id,
				 const GValue *value, GParamSpec *pspec)
{
	PyObject *pyobj;

	switch (property_id) {
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
generalization_get_property (GObject *object, guint property_id,
				 GValue *value, GParamSpec *pspec)
{
	PyObject *pyobj;

	switch (property_id) {
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
generalization_dispose (GObject *object)
{
	G_OBJECT_CLASS (parent_class)->dispose (object);
}


static void
generalization_update (DiaCanvasItem *item, gdouble affine[6])
{
	DIA_CANVAS_ITEM_CLASS (parent_class)->update (item, affine);
}

